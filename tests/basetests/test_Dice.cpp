#pragma once
#include <Dice.hpp>
#include <gtest/gtest.h>
#include <numeric>

// Test invalid constructor argument
TEST(DiceTest, InvalidConstructorNegativeSides) 
{
    EXPECT_THROW(Dice(-4), std::invalid_argument);
}

TEST(DiceTest, InvalidConstructorZeroSides) 
{
    EXPECT_THROW(Dice(0), std::invalid_argument);
}

// Test valid roll results
TEST(DiceTest, RollValidRange) 
{
    Dice test(6);
    for (int i = 0; i < 100; ++i) 
    {
        std::vector<int> results = test.roll(4);
        int sum = std::accumulate(results.begin(), results.end(), 0);

        EXPECT_GE(sum, 4);
        EXPECT_LE(sum, 24);
        
        for (const int& number : results) 
        {
            EXPECT_GE(number, 1);
            EXPECT_LE(number, 6);
        }
    }
}

TEST(DiceTest, RollValidRangeSingleRoll) 
{
    Dice test(12);
    for (int i = 0; i < 100; ++i)
     {
        std::vector<int> results = test.roll(1);
        int sum = std::accumulate(results.begin(), results.end(), 0);

        EXPECT_GE(sum, 1);
        EXPECT_LE(sum, 12);
    }
}

// Test invalid roll argument
TEST(DiceTest, RollInvalidArgument) 
{
    Dice test(6);
    EXPECT_THROW(test.roll(-2), std::invalid_argument);
}

// Additional test for multiple dice rolls
TEST(DiceTest, MultipleDiceRolls) 
{
    Dice test(10);
    std::vector<int> results = test.roll(5);
    EXPECT_EQ(results.size(), 5);
    for (const int& number : results)
    {
        EXPECT_GE(number, 1);
        EXPECT_LE(number, 10);
    }
}
