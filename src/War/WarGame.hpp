#pragma once
#include "WarPlayer.hpp"
#include "WarDeck.hpp"
#include "Game.hpp"

//  Author:
//	    @Tomasz Okoń
//

/**
 * @class WarGame
 * @brief Represents a game of War with two players.
 */
class WarGame : public Game<WarPlayer>
{
protected:
    WarDeck _deck{}; ///< The deck of cards for the game.
    std::vector<std::unique_ptr<StandardCard>> _stack; ///< The stack of cards in the game.

    /**
     * @brief Called when a player wins the game.
     */
    void won() override;

    /**
     * @brief Updates the turn in the game.
     */
    void update_turn() override;

public:
    /**
     * @brief Constructor to initialize a War game.
     */
    WarGame();

    /**
     * @brief Starts the game.
     */
    void start_game() override;

    /**
     * @brief Plays a turn in the game.
     */
    void play() override;

    /**
     * @brief Overloaded output stream operator to display the game state.
     * @param os The output stream.
     * @param game The game instance.
     * @return The output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, WarGame& game);
};
