#pragma once
#include <gtest/gtest.h>
#include "PokerGame.hpp"


// Test fixture for PokerGame class

class PokerGamePublic : public PokerGame
{
public:
    using PokerGame::PokerGame;
    using PokerGame::_players;
};

class PokerGameTest : public ::testing::Test 
{
protected:
    void SetUp() override 
    {
        // Setup code that runs before each test
        game = std::make_unique<PokerGamePublic>(5);
    }

    void TearDown() override
    {
        // Teardown code that runs after each test
        game.reset();
    }

    std::unique_ptr<PokerGamePublic> game;
};

// Test case to check adding players
TEST_F(PokerGameTest, AddPlayer) 
{
    game->add_player("Alice", 1000);
    game->add_player("Bob", 1500);

    ASSERT_EQ(game->_players.size(), 2);
    ASSERT_EQ(game->_players[0]->get_name(), "Alice");
    ASSERT_EQ(game->_players[1]->get_name(), "Bob");
}

// Test case to check removing players
TEST_F(PokerGameTest, RemovePlayer) 
{
    game->add_player("Alice", 1000);
    game->add_player("Bob", 1500);
    game->remove_player(0);

    ASSERT_EQ(game->_players.size(), 1);
    ASSERT_EQ(game->_players[0]->get_name(), "Bob");
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}