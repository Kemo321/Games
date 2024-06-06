#pragma once
#include <vector>
#include <string>
#include "Player.hpp"

//  Author:
//	    @Łukasz Szydlik
//

/**
 * @class Game
 * @brief Template class representing a game with players.
 * @tparam PlayerType The type of players in the game.
 */
template<typename PlayerType>
class Game
{
protected:
    int _turn_number = 1; ///< The current turn number.
    std::vector<PlayerType> _players; ///< Vector of players in the game.

    /**
     * @brief Pure virtual function to determine if a player has won.
     */
    virtual void won() = 0;

    /**
     * @brief Pure virtual function to update the turn.
     */
    virtual void update_turn() = 0;

public:
    /**
     * @brief Default constructor.
     */
    Game() = default;

    /**
     * @brief Virtual destructor.
     */
    virtual ~Game() = default;

    /**
     * @brief Pure virtual function to play the game.
     */
    virtual void play() = 0;

    /**
     * @brief Pure virtual function to start the game.
     */
    virtual void start_game() = 0;

    /**
     * @brief Gets the current turn number.
     * @return The current turn number.
     */
    int get_turn_number() { return _turn_number; }

    /**
     * @brief Adds a player to the game.
     * @param name The name of the player to add.
     */
    void add_player(const std::string& name) { _players.push_back(PlayerType(name)); }

    /**
     * @brief Adds multiple players to the game.
     * @param player_names A vector of player names to add.
     */
    void add_players(const std::vector<std::string>& player_names) { for (const auto& name : player_names) { _players.emplace_back(name); } }
};
