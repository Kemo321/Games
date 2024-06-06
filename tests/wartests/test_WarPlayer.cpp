#pragma once
#include <gtest/gtest.h>
#include "WarPlayer.hpp"
#include "StandardCard.hpp"


class WarPlayerPublic : public WarPlayer
{
public:
    using WarPlayer::_name;
    using WarPlayer::_cards;
    using WarPlayer::take_cards;
    using WarPlayer::WarPlayer;
    using WarPlayer::top_card_info;
};

// Test fixture for WarPlayer
class WarPlayerTest : public ::testing::Test 
{
protected:
    std::vector<std::unique_ptr<StandardCard>> cards;

    void SetUp() override {
        for (int i = 0; i < 5; ++i) 
        {
            cards.push_back(std::make_unique<StandardCard>(static_cast<Rank>(i), static_cast<Colour>(i % 4)));
        }
    }
};

// Test WarPlayer constructor with initial cards
TEST_F(WarPlayerTest, Constructor) 
{
    WarPlayerPublic player("Player1", cards);

    EXPECT_EQ(player._name, "Player1");
    EXPECT_EQ(player._cards.size(), 5);
}

// Test top_card_info method when no cards
TEST(WarPlayerNoCardsTest, TopCardInfoNoCards) 
{
    std::vector<std::unique_ptr<StandardCard>> empty_vector;
    
    WarPlayerPublic player("Player4", empty_vector);

    EXPECT_EQ(player.top_card_info(), "Player has no cards");
}
