#pragma once
#include "Currency.hpp"
#include "Player.hpp"

//  Author:
//	    @Łukasz Szydlik
//

/**
 * @class PigDicesPlayer
 * @brief Represents a player in the Pig Dice game.
 */
class PigDicesPlayer : public Player
{
protected:
    Currency _score{ 0 }; ///< The score of the player.

public:
    /**
     * @brief Constructor to initialize a Pig Dice player with a name.
     * @param name The name of the player.
     */
    PigDicesPlayer(std::string name) : Player(name) {}

    /**
     * @brief Gets the score of the player.
     * @return The score of the player.
     */
    Currency get_value() { return _score; }

    friend class PigDicesGame;
    friend class PigDicesGameTest;
};
