#include <gtest/gtest.h>
#include "PigDicesGame.hpp"

class PigDicesGamePublic : public PigDicesGame
{
public:
    using PigDicesGame::PigDicesGame;
    using PigDicesGame::_simulation;
    using PigDicesGame::_players;
    using PigDicesGame::_make_decision;
};

class PigDicesGameTest : public ::testing::Test 
{
protected:
    PigDicesGamePublic game{{"Player1", "Player2"}};
    PigDicesGameTest() : game({"Player1", "Player2"}) {};
};

TEST_F(PigDicesGameTest, Constructor) 
{
    EXPECT_EQ(game._players.size(), 2);
    EXPECT_EQ(game._simulation, true);
}

TEST_F(PigDicesGameTest, MakeDecisionSimulation) 
{
    game._simulation = true;
    bool decision = game._make_decision();
    EXPECT_TRUE(decision == true || decision == false);
}

TEST_F(PigDicesGameTest, MakeDecisionUserInput) 
{
    game._simulation = false;
    // Mock user input
    std::string input = "n";
    std::istringstream iss(input);
    std::cin.rdbuf(iss.rdbuf());
    bool decision = game._make_decision();
    EXPECT_FALSE(decision);
}

TEST_F(PigDicesGameTest, GetInfo) 
{
    testing::internal::CaptureStdout();
    game.show_turn_info();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}