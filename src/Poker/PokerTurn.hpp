#pragma once
#include <unordered_map>
#include <sstream>
#include <string>
#include <cmath>
#include "../BaseGame/StandardCard.hpp"

//  Author:
//	    @Dominik Śledziewski
//

/**
 * @class PokerTurn
 * @brief Represents a turn in a poker game.
 */
class PokerTurn
{
    int _balance; ///< The player's balance.
    int _money_to_check; ///< The amount of money needed to check.
    int _money_in_pool; ///< The money in the pool.
    std::string _name; ///< The name of the player.
    std::pair<std::shared_ptr<StandardCard>, std::shared_ptr<StandardCard>> _cards; ///< The player's cards.
    std::vector<std::shared_ptr<StandardCard>> _cards_on_table; ///< The cards on the table.

public:
    /**
     * @brief Default constructor.
     */
    PokerTurn();

    /**
     * @brief Constructor to initialize a turn with player details and table cards.
     * @param name The name of the player.
     * @param balance The player's balance.
     * @param cards The player's cards.
     * @param money_to_check The money needed to check.
     * @param money_in_pool The money in the pool.
     * @param cards_on_table The cards on the table.
     */
    PokerTurn(std::string name, int balance, std::pair<std::shared_ptr<StandardCard>, std::shared_ptr<StandardCard>> cards,
        int money_to_check, int money_in_pool, std::vector<std::shared_ptr<StandardCard>> cards_on_table);

    /**
     * @brief Processes the player's input for the turn.
     * @param action The chosen action.
     * @param amount The amount to bet or raise.
     */
    void processInput(int& action, int& amount);

    /**
     * @brief Assignment operator.
     * @param other The PokerTurn to assign from.
     * @return Reference to this PokerTurn.
     */
    PokerTurn& operator=(const PokerTurn& other);

    /**
     * @brief Gets the amount to raise.
     * @return The amount to raise.
     */
    int _get_amount_to_raise() const;

    /**
     * @brief Gets the chosen action.
     * @return The chosen action.
     */
    int _get_chosen_action() const;

    /**
     * @brief Prints the action options to the player.
     */
    void _print_action_options() const;

    /**
     * @brief Overloads the output stream operator for PokerTurn.
     * @param os The output stream.
     * @param turn The PokerTurn to output.
     * @return The output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, PokerTurn& turn);
};
