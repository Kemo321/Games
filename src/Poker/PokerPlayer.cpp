#include "PokerPlayer.hpp"


PokerPlayer::PokerPlayer(std::string& name, int startingBalance)
{
	_name = name;
	_balance = Currency(startingBalance);
}

PokerPlayer::PokerPlayer(const PokerPlayer& other) : _balance(other._balance)
{
	_name = other._name;
}

bool PokerPlayer::is_playing() const
{
	return !_has_folded;
}

int PokerPlayer::get_balance() const
{
	return _balance.get_value();
}

int PokerPlayer::get_money_in_pool() const
{
	return _money_in_pool.get_value();
}

void PokerPlayer::add_balance(int amount)
{
	_balance.add_value(amount);
}

void PokerPlayer::add_money_in_pool(int amount)
{
	_money_in_pool.add_value(amount);
}

void PokerPlayer::give_hand(std::shared_ptr<StandardCard> firstCard, std::shared_ptr<StandardCard> secondCard)
{
	_has_folded = false;
	_money_in_pool.set_value(0);
	_cards.first = std::move(firstCard);
	_cards.second = std::move(secondCard);
}

void PokerPlayer::folded()
{
	_has_folded = true;
}
