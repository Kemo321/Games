#pragma once
#include <gtest/gtest.h>
#include "WarGame.hpp"
#include "StandardCard.hpp"


class WarGamePublic : public WarGame
{
public:
    using WarGame::_players;
    using WarGame::update_turn;
    using WarGame::won;
    using WarGame::WarGame;
};

// Test fixture for WarGame
class WarGameTest : public ::testing::Test 
{
protected:
    WarGamePublic game;
};

// Test WarGame constructor
TEST_F(WarGameTest, Constructor) 
{
    EXPECT_EQ(game.get_turn_number(), 1);
    EXPECT_EQ(game._players.size(), 2);
}

// Test update_turn method
TEST_F(WarGameTest, UpdateTurn) 
{
    game.update_turn();
    EXPECT_EQ(game.get_turn_number(), 2);
}

// Test play method without triggering win condition
TEST_F(WarGameTest, PlayTurn) 
{
    int initial_turn = game.get_turn_number();
    game.play();
    EXPECT_EQ(game.get_turn_number(), initial_turn + 1);
}

// Test won method to ensure it correctly sets the game state
TEST_F(WarGameTest, Won) 
{
    game.won();
    EXPECT_EQ(game.get_turn_number(), -2);
}

// Test operator<< overloading
TEST_F(WarGameTest, OutputOperator)
{
    std::ostringstream output;
    output << game;
    std::string output_str = output.str();
    
    EXPECT_NE(output_str.find("First player's card"), std::string::npos);
    EXPECT_NE(output_str.find("Second player's card"), std::string::npos);
    EXPECT_NE(output_str.find("First player count"), std::string::npos);
    EXPECT_NE(output_str.find("Second player count"), std::string::npos);
    EXPECT_NE(output_str.find("stack"), std::string::npos);
    EXPECT_NE(output_str.find("on stack"), std::string::npos);
}
