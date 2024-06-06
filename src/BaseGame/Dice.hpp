#pragma once
#include <vector>
#include <stdexcept>

//  Author:
//	    @Tomasz Okoń
//

/**
 * @class Dice
 * @brief Represents a dice with a specified number of sides.
 */
class Dice
{
    int _sides; ///< The number of sides on the dice.

public:
    /**
     * @brief Constructor to initialize a dice with a given number of sides.
     * @param sides The number of sides on the dice.
     */
    Dice(int sides = 6);

    /**
     * @brief Default destructor.
     */
    ~Dice() = default;

    /**
     * @brief Rolls the dice a specified number of times.
     * @param tries The number of times to roll the dice.
     * @return A vector of integers representing the results of the rolls.
     */
    std::vector<int> roll(int tries = 1) const;
};
