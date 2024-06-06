#pragma once
#include <gtest/gtest.h>
#include "PokerPlayer.hpp"


// Test fixture for PokerPlayer class
class PokerPlayerTest : public ::testing::Test 
{
protected:
    std::string test="Test";
    PokerPlayer player{test, 1000};
};

// Test case to check if player is playing initially
TEST_F(PokerPlayerTest, IsPlayingInitially)
{
    ASSERT_TRUE(player.is_playing());
}

// Test case to check initial balance
TEST_F(PokerPlayerTest, InitialBalance) 
{
    ASSERT_EQ(player.get_balance(), 1000);
}

// Test case to check initial money in pool
TEST_F(PokerPlayerTest, InitialMoneyInPool) 
{
    ASSERT_EQ(player.get_money_in_pool(), 0);
}

// Test case to check adding balance
TEST_F(PokerPlayerTest, AddBalance) 
{
    player.add_balance(500);
    ASSERT_EQ(player.get_balance(), 1500);
}

// Test case to check adding money to pool
TEST_F(PokerPlayerTest, AddMoneyInPool) 
{
    player.add_money_in_pool(100);
    ASSERT_EQ(player.get_money_in_pool(), 100);
}

// Test case to check giving hand
TEST_F(PokerPlayerTest, GiveHand) 
{
    auto firstCard = std::make_shared<StandardCard>(Rank::Ace, Colour::Heart);
    auto secondCard = std::make_shared<StandardCard>(Rank::King, Colour::Diamond);
    player.give_hand(firstCard, secondCard);
    ASSERT_FALSE(!player.is_playing());
    ASSERT_EQ(player._cards.first, firstCard);
    ASSERT_EQ(player._cards.second, secondCard);
}

// Test case to check folding
TEST_F(PokerPlayerTest, Folded) 
{
    player.folded();
    ASSERT_FALSE(player.is_playing()); // Player should be folded
}
