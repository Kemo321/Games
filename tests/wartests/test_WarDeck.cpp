#pragma once
#include <gtest/gtest.h>
#include "WarDeck.hpp"
#include "StandardCard.hpp"
#include <algorithm>


class WarDeckPublic : public WarDeck
{
public:
    using WarDeck::WarDeck;
    using WarDeck::deal_cards;
};

// Test fixture for WarDeck
class WarDeckTest : public ::testing::Test 
{
protected:
    WarDeckPublic deck;

    void SetUp() override 
    {
        deck.reset();
    }
};

// Test dealing cards from the WarDeck
TEST_F(WarDeckTest, DealCards) 
{
    auto dealt_cards = deck.deal_cards();

    // Check that all cards are unique and accounted for
    std::vector<std::string> all_card_info;
    for (auto& card : dealt_cards.first) 
    {
        all_card_info.push_back(card->get_info());
    }
    for (auto& card : dealt_cards.second) 
    {
        all_card_info.push_back(card->get_info());
    }

    std::sort(all_card_info.begin(), all_card_info.end());
    all_card_info.erase(std::unique(all_card_info.begin(), all_card_info.end()), all_card_info.end());

    EXPECT_EQ(all_card_info.size(), 52);
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}