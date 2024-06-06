#include <gtest/gtest.h>
#include "PigDicesGame.hpp"


class PigDicesPlayerTest : public ::testing::Test 
{
protected:
    PigDicesPlayer player{"TestPlayer"};
    PigDicesPlayerTest() : player("TestPlayer") {}
};

TEST_F(PigDicesPlayerTest, Constructor) 
{
    EXPECT_EQ(player.get_name(), "TestPlayer");
    EXPECT_EQ(player.get_value().get_value(), 0);
}