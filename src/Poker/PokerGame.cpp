#include "PokerGame.hpp"


PokerGame::PokerGame(int smallBlindAmount)
{
	reset_game(smallBlindAmount);
}

void PokerGame::start_game()
{
	if (_players.size() < 2) {
		std::cout << "You cannot start the game with current amount of players! Two players are required.\n";
		_is_over = true;
		return;
	}

	_deal_the_cards();
	_take_blinds();

	while (!_is_over)
	{
		play();
	}
}

void PokerGame::play()
{
	if (_get_previous_playing_player() == _current_player_index && _current_player_index == _get_next_playing_player()) // Only one player not folded
	{
			_end_deal(true);
			_current_player_index = _get_next_playing_player_after_index(_dealer_index);
			return;
	}

	if (_get_current_player()->get_balance() > 0) // If player has money to play, if all-ined waiting for results
	{
		_process_current_player_input();
		
	}
	_moves_in_round++;
	if (is_round_ended())
	{
		if (_state == RoundState::RIVER)
		{
			_end_deal(false); // Have to end this deal, give winner money and give players new cards
		}
		else if (_state == RoundState::LICITATING)
		{
			_draw_cards_on_table(3);
		}
		else
		{
			_draw_cards_on_table(1);
		}
		_state = static_cast<RoundState>((static_cast<int>(_state) + 1) % 4);
		_moves_in_round = 0;
		_current_player_index = _get_next_playing_player_after_index(_dealer_index);
		return;
	}
	_current_player_index = _get_next_playing_player();
}

void PokerGame::add_player(std::string name, int startingBalance)
{
	_players.push_back(std::make_shared<PokerPlayer>(PokerPlayer(name, startingBalance)));
}


void PokerGame::remove_player(int index)
{
	_players.erase(_players.begin() + index);
}

void PokerGame::_take_blinds()
{
	_give_money_to_pool(*(_get_small_blind()), _smallBlindAmount);
	_give_money_to_pool(*(_get_big_blind()), 2 * _smallBlindAmount);
}

void PokerGame::_remove_players_with_no_balance_and_update_dealer_index()
{
	int dealer_index_offset = 1;
	for (int i = 0; i < _players.size(); i++)
	{	
		if (_players[i]->get_balance() < _smallBlindAmount * 2)
		{
			_players.erase(_players.begin() + i);
			i--;
			if (i <= _current_player_index) --dealer_index_offset;
		}
	}
	if (_players.size() < 2)
	{
		won();
	}
	_dealer_index += dealer_index_offset % _players.size();
	_dealer_index = _dealer_index % _players.size();
	_last_player_in_round_index = (_dealer_index + 1) % _players.size();
}

void PokerGame::_give_money_to_pool(PokerPlayer& player, int amount)
{
	_pool.add_value(amount);
	player.add_balance(-amount);
	player.add_money_in_pool(amount);
	_check_amount = _check_amount < player.get_money_in_pool() ? player.get_money_in_pool() : _check_amount;
}

void PokerGame::update_turn()
{
	std::shared_ptr<PokerPlayer> currPlayer = _get_current_player();
	_turn = PokerTurn(currPlayer->get_name(), currPlayer->get_balance(), currPlayer->_cards, compute_amount_to_check(),
		_pool.get_value(), _cards);
}

void PokerGame::_process_current_player_input()
{
	std::shared_ptr<PokerPlayer> player = _get_current_player();
	int action; // 1 - fold, 2 - check, 3 - raise
	int amount;
	update_turn(); // Creates PokerTurn instance based on current round info
	std::cout << _turn;
	_turn.processInput(action, amount);
	if (action == 2)
	{
		amount = compute_amount_to_check() > player->get_balance() ? player->get_balance() : compute_amount_to_check();
		_give_money_to_pool(*_get_current_player(), amount);
	}
	else if (action == 3)
	{
		_give_money_to_pool(*_get_current_player(), amount);
		_last_player_in_round_index = _current_player_index;
	}
	else
	{
		player->folded();
	}
}

void PokerGame::_draw_cards_on_table(int amount)
{
	for (int i = 0; i < amount; i++)
	{
		_cards.push_back(std::move(_deck.draw_random()));
	}
}

void PokerGame::_end_deal(bool folded)
{
	std::shared_ptr<PokerPlayer> winner;
	if (folded)
	{
		winner = _players[_get_next_playing_player()];
	}
	else
	{
		winner = _get_winner();

	}
	winner->add_balance(_pool.get_value());
	_announce_the_winner(*winner);

	_check_amount = 0;
	_cards.clear();
	_pool.set_value(0);
	_remove_players_with_no_balance_and_update_dealer_index();
	_deal_the_cards();
	_take_blinds();
	_deck.reset();
}


bool PokerGame::is_round_ended() const
{
	if (_moves_in_round < 2 || _current_player_index != _last_player_in_round_index) return false;
	for (const std::shared_ptr<PokerPlayer> player : _players)
	{
		if (!player->is_playing()) continue;
		if (player->get_money_in_pool() != _check_amount && player->get_balance() > 0) return false;
	}
	return true;
}

void PokerGame::_announce_the_winner(PokerPlayer& winner) const
{
	std::cout << "---------------------------------------------------------------------------------------------------------------------------\n"
		<< "The hand has ended!\n" <<  winner.get_name() << " won!\n"
		<< "---------------------------------------------------------------------------------------------------------------------------\n";
}

std::shared_ptr<PokerPlayer> PokerGame::_get_winner()
{
	int maxScore = 0;
	std::shared_ptr<PokerPlayer> winner;
	std::vector<std::shared_ptr<StandardCard>> combinedCards;
	for (const std::shared_ptr<PokerPlayer> player : _players)
	{ 
		if (!player->is_playing()) continue;
		combinedCards.insert(combinedCards.end(), _cards.begin(), _cards.end());
		combinedCards.push_back(player->_cards.first);
		combinedCards.push_back(player->_cards.second);
		int score = _calculate_score(combinedCards);
		combinedCards.clear();
		if (maxScore < score)
		{
			winner = player;
			maxScore = score;
		}
	}
	return winner;
}

int PokerGame::_calculate_score(std::vector<std::shared_ptr<StandardCard>>& cards)
{
	int maxScore = 0;
	int score = 0;
	std::vector<std::shared_ptr<StandardCard>> caseCards;
	for (int i = 0; i < 6; i++)
	{

		for (int j = i + 1; j < 7; j++)
		{
			for (int k = 0; k < 7; k++)
			{
				if (k != i && k != j)
				{
					caseCards.push_back(cards[k]);
				}
			}
			score = _get_score(caseCards);
			maxScore = maxScore < score ? score : maxScore;
			caseCards.clear();
		}
	}
	return maxScore;
}

bool PokerGame::_is_straight(std::vector<Rank>& ranks) const{
	for (int i = 1; i < ranks.size(); ++i) {
		if (static_cast<int>(ranks[i]) != static_cast<int>(ranks[i - 1]) + 1) {
			return false;
		}
	}
	return true;
};

int PokerGame::_get_score(std::vector<std::shared_ptr<StandardCard>>& cards)
{
	int score = 0;
	std::unordered_map<Colour, int> colourCount;
	std::unordered_map<Rank, int> rankCount;
	std::vector<Rank> ranks;

	for (const auto& card : cards)
	{
		colourCount[card->get_colour()]++;
		rankCount[card->get_rank()]++;
		ranks.push_back(card->get_rank());
	}

	std::sort(ranks.begin(), ranks.end(), [](Rank a, Rank b) {
		return static_cast<int>(a) < static_cast<int>(b);
		});
	bool flush = (colourCount.size() == 1);
	bool straight = _is_straight(ranks);
	bool straightFlush = flush && straight;
	bool fourOfAKind = false;
	bool threeOfAKind = false;
	bool pairs = false;
	int pairRank = 0;
	int highestCardValue = static_cast<int>(ranks[4]);

	if (straightFlush)
	{
		score += 10000000;
		score += highestCardValue * 10;
		return score;
	}

	for (const auto& pair : rankCount)
	{
		if (pair.second == 4) fourOfAKind = true;
		else if (pair.second == 3) threeOfAKind = true;
		else if (pair.second == 2)
		{
			int cardRank = static_cast<int>(pair.first);
			pairs = true;
			if (cardRank != 0)
			{
				if (cardRank > pairRank) pairRank += cardRank * 100;
				else
				{
					pairRank *= 100;
					pairRank += cardRank;
				}
			}
			else pairRank += cardRank;
		}
	}
	if (fourOfAKind)
	{
		score += 9000000;
		score += static_cast<int>(ranks[2]) * 100;
		score += highestCardValue;
	}
	else if (threeOfAKind && pairs)
	{
		score += 8000000;
	}
	else if (flush)
	{
		score += 7000000;
		score += highestCardValue;
	}
	else if (straight)
	{
		score += 6000000;
		score += highestCardValue;
	}
	else if (threeOfAKind)
	{
		score += 5000000;
		score += static_cast<int>(ranks[2]) * 100;
		score += highestCardValue;
	}
	else if (pairs && pairRank > 50)
	{
		score += 4000000;
		score += pairRank * 100;
		score += highestCardValue;
	}
	else if (pairs)
	{
		score += 3000000;
		score += pairRank * 100;
		score += highestCardValue;
	}
	else score = highestCardValue;
	return score;

}

int PokerGame::_get_next_playing_player_after_index(int index) const
{
	for (int i = index + 1; i < _players.size() + index; i++)
	{
		if (_players[i % _players.size()]->is_playing())
		{
			return i % _players.size();
		}
	}
	return _current_player_index;
}

int PokerGame::_get_next_playing_player() const
{
	for (int i = _current_player_index + 1; i < _players.size() + _current_player_index; i++)
	{
		if (_players[i % _players.size()]->is_playing())
		{
			return i % _players.size();
		}
	}
	return _current_player_index;
}

int PokerGame::_get_previous_playing_player() const
{
	for (int i = _current_player_index + _players.size() - 1; i > _current_player_index; i--)
	{
		if (_players[i % _players.size()]->is_playing())
		{
			return i % _players.size();
		}
	}
	return _current_player_index;
}


std::shared_ptr<PokerPlayer> PokerGame::_get_dealer() const
{
	return _players[_dealer_index % _players.size()];
}

std::shared_ptr<PokerPlayer> PokerGame::_get_small_blind() const
{
	return _players[(_dealer_index + 1) % _players.size()];
}

std::shared_ptr<PokerPlayer> PokerGame::_get_big_blind() const
{
	return _players[(_dealer_index + 2) % _players.size()];
}

std::shared_ptr<PokerPlayer> PokerGame::_get_current_player() const
{
	return _players[_current_player_index];
}

void PokerGame::_deal_the_cards()
{
	for (const std::shared_ptr<PokerPlayer> player : _players)
	{
		player->give_hand(std::move(_deck.draw_random()), std::move(_deck.draw_random()));
	}
}

void PokerGame::reset_game(int smallBlindAmount)
{
	_smallBlindAmount = smallBlindAmount;
	_last_player_in_round_index = 0;
	_cards.clear();
	_players.clear();
	_check_amount = 0;
	_moves_in_round = 0;
	_dealer_index = _players.size() - 1;
	_current_player_index = 0;
	_state = RoundState::LICITATING;
	_is_over = false;
}

void PokerGame::won()
{
	std::cout << "*********************************************************************************************************\n"
		<< "Congratulations, " << _get_dealer()->get_name() << " has won!" << std::endl
		<< "*********************************************************************************************************\n";
	_is_over = true;
}
int PokerGame::compute_amount_to_check() const
{
	return _check_amount - _get_current_player()->get_money_in_pool();
}
