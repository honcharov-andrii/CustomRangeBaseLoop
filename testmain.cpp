#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "customcontainer.h"

const uint8_t SIZE = 10;

TEST(FirstTestCase, TestSuccessResult)
{
    CustomContainer<size_t> container(SIZE);

    ASSERT_EQ(container.begin(), &container[0]);
    ASSERT_EQ(--container.end(), &container[SIZE - 1]);

    for(size_t i = 0; i < SIZE; ++i)
    {
        container[i] = i;
    }

    for(size_t i = 0; i < SIZE; ++i)
    {
        container[i] = i;

        ASSERT_EQ(i, container[i]);
    }

    size_t count = 0;
    for(auto it : container)
    {
        ASSERT_EQ(it, container[count]);
        ++count;
    }
}


int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
