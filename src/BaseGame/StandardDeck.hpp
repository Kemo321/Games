#pragma once
#include "Deck.hpp"
#include "StandardCard.hpp"
#include <vector>
#include <memory>

//  Author:
//	    @Dominik Śledziewski
//

/**
 * @class StandardDeck
 * @brief Represents a standard deck of playing cards.
 */
class StandardDeck : public Deck<StandardCard>
{
public:
    /**
     * @brief Constructor to initialize a standard deck of cards.
     */
    StandardDeck();

    /**
     * @brief Destructor.
     */
    ~StandardDeck() = default;

    /**
     * @brief Resets the deck to the initial state.
     */
    void reset() override;

    /**
     * @brief Gets the cards in the deck.
     * @return A vector of unique pointers to the cards in the deck.
     */
    const std::vector<std::unique_ptr<StandardCard>>& get_cards() const { return _cards; }
};
