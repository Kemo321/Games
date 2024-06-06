#pragma once
#include "PigDicesPlayer.hpp"
#include "Dice.hpp"
#include "Game.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory>

//  Author:
//	    @Łukasz Szydlik
//

/**
 * @class PigDicesGame
 * @brief Represents a game of Pig Dice.
 */
class PigDicesGame : public Game<PigDicesPlayer>
{
    Dice _dice = Dice(6); ///< The dice used in the game.
    bool _simulation = true; ///< Indicates if the game is in simulation mode.
    bool _game_running = true; ///< Indicates if the game is currently running.
    bool _decision = false; ///< Indicates the player's decision to roll again.

    const int _winning_points = 100; ///< The points required to win the game.
    int _turn_score = 0; ///< The score for the current turn.
    int _current_player_index = 0; ///< The index of the current player.

    std::vector<int> _actual_rools; ///< The results of the dice rolls.
    std::vector<std::shared_ptr<PigDicesPlayer>> _players; ///< The players in the game.
    std::shared_ptr<PigDicesPlayer> _current_player; ///< The current player.

    /**
     * @brief Called when a player wins the game.
     */
    void won() override;

    /**
     * @brief Updates the turn in the game.
     */
    void update_turn() override;

    /**
     * @brief Makes a decision to roll again or hold.
     * @return True if the player decides to roll again, false otherwise.
     */
    bool _make_decision();

public:
    /**
     * @brief Constructor to initialize a Pig Dice game with player names.
     * @param player_names The names of the players.
     */
    PigDicesGame(std::vector<std::string> player_names = {});

    /**
     * @brief Plays a turn in the game.
     */
    void play() override;

    /**
     * @brief Starts the game.
     */
    void start_game() override;

    /**
     * @brief Shows information about the current turn.
     */
    void show_turn_info();

    /**
     * @brief Adds a player to the game.
     * @param name The name of the player.
     */
    void add_player(const std::string& name);

    /**
     * @brief Adds multiple players to the game.
     * @param player_names The names of the players.
     */
    void add_players(const std::vector<std::string>& player_names);

    friend class PigDicesGamePublic;
};
