#pragma once
#include <gtest/gtest.h>
#include "PokerTurn.hpp"


// Test fixture for PokerTurn class
class PokerTurnTest : public ::testing::Test 
{
protected:
    void SetUp() override 
    {
        auto firstCard = std::make_shared<StandardCard>(Rank::Ace, Colour::Heart);
        auto secondCard = std::make_shared<StandardCard>(Rank::King, Colour::Diamond);
        std::vector<std::shared_ptr<StandardCard>> cardsOnTable = {
            std::make_shared<StandardCard>(Rank::Queen, Colour::Spade),
            std::make_shared<StandardCard>(Rank::Jack, Colour::Club)
        };
        turn = PokerTurn("Alice", 1000, std::make_pair(firstCard, secondCard), 10, 50, cardsOnTable);
    }

    PokerTurn turn;
};

// Test case to check processInput function for folding
TEST_F(PokerTurnTest, Fold) 
{
    std::istringstream input("1");
    std::cin.rdbuf(input.rdbuf());
    int action, amount;
    turn.processInput(action, amount);
    ASSERT_EQ(action, 1);
}

// Test case to check processInput function for checking
TEST_F(PokerTurnTest, Check) 
{
    std::istringstream input("2");
    std::cin.rdbuf(input.rdbuf());
    int action, amount;
    turn.processInput(action, amount);
    ASSERT_EQ(action, 2);
}

// Test case to check processInput function for raising
TEST_F(PokerTurnTest, Raise) 
{
    std::istringstream input("3\n100");
    std::cin.rdbuf(input.rdbuf());
    int action, amount;
    turn.processInput(action, amount);
    ASSERT_EQ(action, 3);
    ASSERT_EQ(amount, 110);
}
