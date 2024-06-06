#include <gtest/gtest.h>
#include "StandardCard.hpp"

// Test fixture for StandardCard
class StandardCardTest : public ::testing::Test 
{
protected:
    StandardCard card1;
    StandardCard card2;
    StandardCard card3;
    StandardCard card7;

    // Initialize the cards in the constructor
    StandardCardTest()
        : card1(Rank::Ace, Colour::Spade), 
          card2(Rank::King, Colour::Heart),
          card3(Rank::Three, Colour::Club),
          card7(Rank::Seven, Colour::Diamond) {}
};

// Test the constructor and getters
TEST_F(StandardCardTest, ConstructorAndGetters) 
{
    EXPECT_EQ(card1.get_rank(), Rank::Ace);
    EXPECT_EQ(card1.get_colour(), Colour::Spade);
    EXPECT_EQ(card2.get_rank(), Rank::King);
    EXPECT_EQ(card2.get_colour(), Colour::Heart);
    EXPECT_EQ(card3.get_rank(), Rank::Three);
    EXPECT_EQ(card3.get_colour(), Colour::Club);
    EXPECT_EQ(card7.get_rank(), Rank::Seven);
    EXPECT_EQ(card7.get_colour(), Colour::Diamond);
}

// Test the equality operator
TEST_F(StandardCardTest, EqualityOperator) 
{
    StandardCard anotherAceOfSpades(Rank::Ace, Colour::Spade);
    EXPECT_EQ(card1, anotherAceOfSpades);
    EXPECT_NE(card1, card2);
    EXPECT_NE(card1, card3);
    EXPECT_NE(card1, card7);
}

// Test the less than operator
TEST_F(StandardCardTest, LessThanOperator) 
{
    EXPECT_TRUE(card2 < card1);
    EXPECT_FALSE(card1 < card2);
    EXPECT_TRUE(card3 < card1);
    EXPECT_TRUE(card3 < card2);
    EXPECT_TRUE(card7 < card1);
    EXPECT_TRUE(card7 < card2);
}

// Test the greater than operator
TEST_F(StandardCardTest, GreaterThanOperator) 
{
    EXPECT_TRUE(card1 > card2);
    EXPECT_FALSE(card2 > card1);
    EXPECT_TRUE(card1 > card3);
    EXPECT_TRUE(card2 > card3);
    EXPECT_TRUE(card1 > card7);
    EXPECT_TRUE(card2 > card7);
    EXPECT_TRUE(card7 > card3);
}

// Test the get_info method
TEST_F(StandardCardTest, GetInfo) 
{
    EXPECT_EQ(card1.get_info(), "Ace Spade");
    EXPECT_EQ(card2.get_info(), "King Heart");
    EXPECT_EQ(card3.get_info(), "3 Club");
    EXPECT_EQ(card7.get_info(), "7 Diamond");
}
