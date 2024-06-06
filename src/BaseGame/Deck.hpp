#pragma once
#include "Card.hpp"
#include <memory>
#include <vector>

//  Author:
//	    @Tomasz Okoń
//

/**
 * @class Deck
 * @brief Template class representing a deck of cards.
 * @tparam CardType The type of cards in the deck.
 */
template <typename CardType>
class Deck
{
protected:
    std::vector<std::unique_ptr<CardType>> _cards; ///< Vector of unique pointers to cards.

public:
    /**
     * @brief Draws a random card from the deck.
     * @return A unique pointer to the drawn card.
     */
    std::unique_ptr<CardType> draw_random()
    {  
        std::srand(time(NULL));
        int index = std::rand() % _cards.size();
        std::unique_ptr<CardType> ptr = std::move(_cards[index]);
        _cards.erase(_cards.begin() + index);
        return ptr;
    }

    /**
     * @brief Pure virtual function to reset the deck.
     */
    virtual void reset() = 0;

    /**
     * @brief Default constructor.
     */
    Deck() = default;

    /**
     * @brief Virtual destructor.
     */
    virtual ~Deck() = default;
};
