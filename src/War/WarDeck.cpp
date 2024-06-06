#include "WarDeck.hpp"
#include <random>
#include <algorithm>
#include "StandardCard.hpp"
#include <iostream>


std::pair<std::vector<std::unique_ptr<StandardCard> >, std::vector<std::unique_ptr<StandardCard> > > WarDeck::deal_cards()
{
    std::vector<std::unique_ptr<StandardCard> > first; // First player
    std::vector<std::unique_ptr<StandardCard> > second; // Second player
    std::vector<std::unique_ptr<StandardCard> > cards_pointers;

    for (auto& card : this->_cards)
    {
        cards_pointers.push_back(std::move(card));
    } 

    // Clear the original _cards vector
    this->_cards.clear();

    // Shuffle the cards
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards_pointers.begin(), cards_pointers.end(), g);

    // Deal cards to players
    for (size_t i = 0; i < cards_pointers.size(); i++)
    {
        if (i % 2 == 0)
        {
            first.push_back(std::move(cards_pointers[i]));
        }
        else
        {
            second.push_back(std::move(cards_pointers[i]));
        }
    }

    // Return the pair of vectors containing the shuffled cards for each player
    return std::make_pair(std::move(first), std::move(second));
}