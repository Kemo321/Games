#pragma once
#include <memory>
#include <vector>
#include <utility>
#include "StandardDeck.hpp"

//  Author:
//	    @Tomasz Okoń
//

/**
 * @class WarDeck
 * @brief Represents a deck of cards specifically for the game of War.
 */
class WarDeck : public StandardDeck
{
protected:
    /**
     * @brief Deals cards between two players.
     * @return A pair of vectors, each containing the cards for one player.
     */
    std::pair<std::vector<std::unique_ptr<StandardCard>>, std::vector<std::unique_ptr<StandardCard>>> deal_cards();

public:
    /**
     * @brief Constructor to initialize a War deck.
     */
    WarDeck() : StandardDeck() {}

    friend class WarGame;
};
