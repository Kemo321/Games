#pragma once
#include <string>
#include <memory>
#include <vector>

//  Author:
//	    @Łukasz Szydlik
//

/**
 * @class Player
 * @brief Represents a player with a name.
 */
class Player
{
protected:
    std::string _name; ///< The name of the player.

public:
    /**
     * @brief Default constructor.
     */
    Player() = default;

    /**
     * @brief Constructor to initialize a player with a given name.
     * @param name The name of the player.
     */
    Player(std::string name) : _name(name) {}

    /**
     * @brief Gets the name of the player.
     * @return The name of the player.
     */
    std::string get_name() { return _name; }
};
