/*
Given a year, report if it is a leap year.

The tricky thing here is that a leap year in the Gregorian calendar occurs:

on every year that is evenly divisible by 4
  except every year that is evenly divisible by 100
    unless the year is also evenly divisible by 400

For example, 1997 is not a leap year, but 1996 is. 1900 is not a leap year, but 2000 is.

If your language provides a method in the standard library that does this look-up, pretend it doesn't exist and implement it yourself.
*/

#include <gtest/gtest.h>

bool IsLeapYear(int year)
{
    return (year % 100 == 0) ? (year % 400 == 0) : (year % 4 == 0);
}

TEST(YearTest, OrdinaryYear)
{
    EXPECT_FALSE(IsLeapYear(1997));
}

TEST(YearTest, OrdinaryYearSecond)
{
    EXPECT_FALSE(IsLeapYear(1995));
}

TEST(YearTest, LeapYear)
{
    EXPECT_TRUE(IsLeapYear(1996));
}

TEST(YearTest, OrdinaryYearDerivedBy100)
{
    EXPECT_FALSE(IsLeapYear(1900));
}

TEST(YearTest, OrdinaryYearDerivedBy400)
{
    EXPECT_TRUE(IsLeapYear(2000));
}

TEST(YearTest, AcceptenceTest)
{
    EXPECT_TRUE(IsLeapYear(1952));
    EXPECT_TRUE(IsLeapYear(1956));
    EXPECT_TRUE(IsLeapYear(1960));
    EXPECT_TRUE(IsLeapYear(1964));
    EXPECT_TRUE(IsLeapYear(1968));
    EXPECT_TRUE(IsLeapYear(1972));
    EXPECT_TRUE(IsLeapYear(1976));

    EXPECT_FALSE(IsLeapYear(1953));
    EXPECT_FALSE(IsLeapYear(1957));
    EXPECT_FALSE(IsLeapYear(1961));
    EXPECT_FALSE(IsLeapYear(421));
    EXPECT_FALSE(IsLeapYear(643));
    EXPECT_FALSE(IsLeapYear(121));
    EXPECT_FALSE(IsLeapYear(75));

    ASSERT_NO_THROW(IsLeapYear(100));
}
