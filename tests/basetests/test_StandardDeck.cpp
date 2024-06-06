#include <gtest/gtest.h>
#include "StandardDeck.hpp"
#include <unordered_set>

// Test fixture for StandardDeck
class StandardDeckTest : public ::testing::Test 
{
protected:
    StandardDeck deck;

    // Function to check if a deck contains 52 unique cards
    bool contains52UniqueCards(const std::vector<std::unique_ptr<StandardCard>>& cards) 
    {
        std::unordered_set<std::string> cardSet;
        for (const auto& card : cards) 
        {
            cardSet.insert(card->get_info());
        }
        return cardSet.size() == 52;
    }
};

// Test the constructor and reset method
TEST_F(StandardDeckTest, ConstructorAndReset) 
{
    // Check if the deck is initialized with 52 unique cards
    EXPECT_EQ(deck.get_cards().size(), 52);
    EXPECT_TRUE(contains52UniqueCards(deck.get_cards()));
    
    // Draw all cards to empty the deck
    for (int i = 0; i < 52; ++i) 
    {
        deck.draw_random();
    }

    // Check if the deck is empty
    EXPECT_EQ(deck.get_cards().size(), 0);

    // Reset the deck
    deck.reset();

    // Check if the deck is reinitialized with 52 unique cards
    EXPECT_EQ(deck.get_cards().size(), 52);
    EXPECT_TRUE(contains52UniqueCards(deck.get_cards()));
}

// Test the draw_random method
TEST_F(StandardDeckTest, DrawRandom) 
{
    std::unordered_set<std::string> drawnCards;

    // Draw 10 cards and store their info
    for (int i = 0; i < 10; ++i) 
    {
        auto card = deck.draw_random();
        EXPECT_TRUE(card != nullptr);
        drawnCards.insert(card->get_info());
    }

    // Check if 10 unique cards were drawn
    EXPECT_EQ(drawnCards.size(), 10);

    // Check if the deck size is reduced by 10
    EXPECT_EQ(deck.get_cards().size(), 42);
}

// Test drawing all cards from the deck
TEST_F(StandardDeckTest, DrawAllCards) 
{
    std::unordered_set<std::string> drawnCards;

    // Draw all 52 cards
    for (int i = 0; i < 52; ++i) 
    {
        auto card = deck.draw_random();
        EXPECT_TRUE(card != nullptr);
        drawnCards.insert(card->get_info());
    }

    // Check if 52 unique cards were drawn
    EXPECT_EQ(drawnCards.size(), 52);

    // Check if the deck is empty
    EXPECT_EQ(deck.get_cards().size(), 0);
}
