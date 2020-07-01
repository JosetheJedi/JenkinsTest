#include <gtest/gtest.h>
#include "../Example.hpp"

TEST(ExampleTests, trueorfalsetest)
{
    ASSERT_TRUE(true);
}

TEST(ExampleTests, anotherTest)
{
    ASSERT_TRUE(true);

    Example ex = Example();
}