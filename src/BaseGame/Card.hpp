#pragma once
#include <string>

//  Author:
//	    @Tomasz Okoń
//

/**
 * @class Card
 * @brief Represents a basic card with a name.
 */
class Card
{
protected:
    std::string _name; ///< The name of the card.

public:
    /**
     * @brief Constructor to initialize a card with a given name.
     * @param name The name of the card.
     */
    Card(std::string name = "") : _name(name) {}

    /**
     * @brief Virtual destructor.
     */
    virtual ~Card() = default;

    /**
     * @brief Gets the name of the card.
     * @return The name of the card.
     */
    std::string get_name() const { return _name; }

    /**
     * @brief Pure virtual function to get card information.
     * @return The information of the card.
     */
    virtual std::string get_info() const = 0;
};