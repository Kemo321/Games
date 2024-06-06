#pragma once
#include "PokerTurn.hpp"
#include <memory>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <iostream>
#include "../BaseGame/StandardCard.hpp"
#include "../BaseGame/StandardDeck.hpp"
#include "../BaseGame/Game.hpp"
#include "PokerPlayer.hpp"

//  Author:
//	    @Dominik Śledziewski
//

/**
 * @enum RoundState
 * @brief Enumeration for the state of the round in a poker game.
 */
enum class RoundState
{
    LICITATING,
    FLOP,
    TURN,
    RIVER
};

/**
 * @class PokerGame
 * @brief Represents a poker game with multiple players.
 */
class PokerGame : public Game<std::shared_ptr<PokerPlayer>>
{
protected:
    bool _is_over; ///< Indicates if the game is over.
    int _check_amount; ///< The amount required to check for player with no money in pool.
    int _moves_in_round; ///< The number of moves in the current round.
    int _dealer_index; ///< The index of the dealer.
    int _last_player_in_round_index; ///< The index of the last player in the round.
    int _current_player_index; ///< The index of the current player.
    int _smallBlindAmount; ///< The amount for the small blind.
    std::vector<std::shared_ptr<StandardCard>> _cards; ///< The cards on the table.
    std::vector<std::shared_ptr<PokerPlayer>> _players; ///< The players in the game.
    Currency _pool; ///< The current pool of money.
    PokerTurn _turn; ///< The current turn information.
    RoundState _state; ///< The current state of the round.
    StandardDeck _deck; ///< The deck of cards.

    /**
     * @brief Checks if the current round has ended.
     * @return True if the round has ended, false otherwise.
     */
    bool is_round_ended() const;

    /**
     * @brief Checks if the given ranks form a straight.
     * @param ranks The ranks to check.
     * @return True if the ranks form a straight, false otherwise.
     */
    bool _is_straight(std::vector<Rank>& ranks) const;

    /**
     * @brief Gets the winner of the current hand.
     * @return A shared pointer to the winning player.
     */
    std::shared_ptr<PokerPlayer> _get_winner();

    /**
     * @brief Calculates the score for the given cards.
     * @param cards The cards to calculate the score for.
     * @return The score of the cards.
     */
    int _calculate_score(std::vector<std::shared_ptr<StandardCard>>& cards);

    /**
     * @brief Gets the score for the given cards.
     * @param cards The cards to get the score for.
     * @return The score of the cards.
     */
    int _get_score(std::vector<std::shared_ptr<StandardCard>>& cards);

    /**
     * @brief Gets the index of the next playing player after the given index.
     * @param index The index to start from.
     * @return The index of the next playing player.
     */
    int _get_next_playing_player_after_index(int index) const;

    /**
     * @brief Gets the index of the next playing player.
     * @return The index of the next playing player.
     */
    int _get_next_playing_player() const;

    /**
     * @brief Gets the index of the previous playing player.
     * @return The index of the previous playing player.
     */
    int _get_previous_playing_player() const;

    /**
     * @brief Announces the winner of the current round.
     * @param winner The winning player.
     */
    void _announce_the_winner(PokerPlayer& winner) const;

    /**
     * @brief Take maney from big blind and small blind players to the pool.
     */
    void _take_blinds();

    /**
     * @brief Removes players with no balance and updates the dealer index.
     */
    void _remove_players_with_no_balance_and_update_dealer_index();

    /**
     * @brief Gives money to the pool from the given player.
     * @param player The player to take money from.
     * @param amount The amount of money to take.
     */
    void _give_money_to_pool(PokerPlayer& player, int amount);

    /**
     * @brief Processes the input from the current player.
     */
    void _process_current_player_input();

    /**
     * @brief Draws the given amount of cards on the table.
     * @param amount The amount of cards to draw.
     */
    void _draw_cards_on_table(int amount);

    /**
     * @brief Ends the current deal.
     * @param folded Indicates if the deal ended with a fold.
     */
    void _end_deal(bool folded);

    /**
     * @brief Deals the cards to the players.
     */
    void _deal_the_cards();

    /**
     * @brief Gets the dealer player.
     * @return A shared pointer to the dealer player.
     */
    std::shared_ptr<PokerPlayer> _get_dealer() const;

    /**
     * @brief Gets the small blind player.
     * @return A shared pointer to the small blind player.
     */
    std::shared_ptr<PokerPlayer> _get_small_blind() const;

    /**
     * @brief Gets the big blind player.
     * @return A shared pointer to the big blind player.
     */
    std::shared_ptr<PokerPlayer> _get_big_blind() const;

    /**
     * @brief Gets the current player.
     * @return A shared pointer to the current player.
     */
    std::shared_ptr<PokerPlayer> _get_current_player() const;

public:
    /**
     * @brief Constructor to initialize a poker game with a given small blind amount.
     * @param smallBlindAmount The amount for the small blind.
     */
    PokerGame(int smallBlindAmount = 5);

    /**
     * @brief Starts the poker game.
     */
    void start_game() override;

    /**
     * @brief Plays the current round of the game.
     */
    void play() override;

    /**
     * @brief Adds a player to the game.
     * @param name The name of the player.
     * @param startingBalance The starting balance for the player.
     */
    void add_player(std::string name, int startingBalance);

    /**
     * @brief Removes a player from the game.
     * @param index The index of the player to remove.
     */
    void remove_player(int index);

    /**
     * @brief Updates the turn information.
     */
    void update_turn() override;

    /**
     * @brief Resets the game with a given small blind amount.
     * @param smallBlindAmount The amount for the small blind.
     */
    void reset_game(int smallBlindAmount = 5);

    /**
     * @brief Handles the end of the game.
     */
    void won() override;

    /**
     * @brief Computes the amount required to check for the current player.
     * @return The amount required to check.
     */
    int compute_amount_to_check() const;
};
