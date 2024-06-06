#pragma once
#include <Currency.hpp>
#include <gtest/gtest.h>

// Test constructors
TEST(CurrencyTest, DefaultConstructor) 
{
    Currency currency;
    EXPECT_EQ(currency.get_value(), 0);
}

TEST(CurrencyTest, PositiveValueConstructor) 
{
    Currency currency(100);
    EXPECT_EQ(currency.get_value(), 100);
}

TEST(CurrencyTest, NegativeValueConstructor) 
{
    Currency currency(-100);
    EXPECT_EQ(currency.get_value(), -100);
}

// Test set_value method
TEST(CurrencyTest, set_valuePositive)
{
    Currency currency;
    currency.set_value(50);
    EXPECT_EQ(currency.get_value(), 50);
}

TEST(CurrencyTest, set_valueNegative) 
{
    Currency currency;
    currency.set_value(-50);
    EXPECT_EQ(currency.get_value(), -50);
}

// Test add_value method
TEST(CurrencyTest, AddPositiveValue) 
{
    Currency currency;
    currency.set_value(50);
    currency.add_value(100);
    EXPECT_EQ(currency.get_value(), 150);
}

TEST(CurrencyTest, AddNegativeValue) 
{
    Currency currency;
    currency.set_value(50);
    currency.add_value(-100);
    EXPECT_EQ(currency.get_value(), -50);
}

// Test update_value method
TEST(CurrencyTest, update_valueMultiply) 
{
    Currency currency(100);
    currency.update_value([](int oldValue) { return oldValue * 2; });
    EXPECT_EQ(currency.get_value(), 200);
}

TEST(CurrencyTest, update_valueDivide) 
{
    Currency currency(33);
    currency.update_value([](int oldValue) { return oldValue / 2; });
    EXPECT_EQ(currency.get_value(), 16);
}

TEST(CurrencyTest, add_valueZero)
{
    Currency currency(50);
    currency.add_value(0);
    EXPECT_EQ(currency.get_value(), 50);
}

TEST(CurrencyTest, set_valueToZero) 
{
    Currency currency(100);
    currency.set_value(0);
    EXPECT_EQ(currency.get_value(), 0);
}

TEST(CurrencyTest, update_valueNoChange) 
{
    Currency currency(100);
    currency.update_value([](int oldValue) { return oldValue; });
    EXPECT_EQ(currency.get_value(), 100);
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}