#include <gtest/gtest.h>
#include "../Example.hpp"

TEST(SecondTests, firstTestCase)
{
    ASSERT_TRUE(true);
}

TEST(SecondTests, secondTestCase)
{
    ASSERT_TRUE(false);

    Example ex = Example();
}

TEST(SecondTests, thirdTestCase)
{
    ASSERT_TRUE(true);
}