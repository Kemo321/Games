#pragma once
#include <utility>
#include "../BaseGame/Currency.hpp"
#include "../BaseGame/StandardCard.hpp"
#include "../BaseGame/Player.hpp"
#include <memory>
#include <vector>

//  Author:
//	    @Dominik Śledziewski
//

/**
 * @class PokerPlayer
 * @brief Represents a player in a poker game.
 */
class PokerPlayer : public Player
{
    bool _has_folded = false; ///< Indicates whether the player has folded.
    Currency _balance; ///< The player's balance.
    Currency _money_in_pool; ///< The money the player has in the pool.

public:
    /**
     * @brief Constructor to initialize a poker player with a name and starting balance.
     * @param name The name of the player.
     * @param starting_balance The initial balance of the player.
     */
    PokerPlayer(std::string& name, int starting_balance = 1000);

    /**
     * @brief Copy constructor.
     * @param other The PokerPlayer to copy from.
     */
    PokerPlayer(const PokerPlayer& other);

    /**
     * @brief Checks if the player is still playing.
     * @return True if the player has not folded, false otherwise.
     */
    bool is_playing() const;

    /**
     * @brief Gets the player's balance.
     * @return The player's balance.
     */
    int get_balance() const;

    /**
     * @brief Gets the money the player has in the pool.
     * @return The money in the pool.
     */
    int get_money_in_pool() const;

    /**
     * @brief Adds an amount to the player's balance.
     * @param amount The amount to add.
     */
    void add_balance(int amount);

    /**
     * @brief Adds an amount to the money in the pool.
     * @param amount The amount to add.
     */
    void add_money_in_pool(int amount);

    /**
     * @brief Gives the player a hand of two cards.
     * @param first_card The first card.
     * @param second_card The second card.
     */
    void give_hand(std::shared_ptr<StandardCard> first_card, std::shared_ptr<StandardCard> second_card);

    /**
     * @brief Sets the player's state to folded.
     */
    void folded();

    std::pair<std::shared_ptr<StandardCard>, std::shared_ptr<StandardCard>> _cards; ///< The player's cards.
};
