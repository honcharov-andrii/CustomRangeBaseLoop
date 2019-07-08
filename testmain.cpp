#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

/*TEST(FirstTestCase, TestSuccessResult)
{
    CResult<int> result = CResult<int>::createSuccessResult(10);

    ASSERT_EQ(result.isResultAvailable(), true);
    ASSERT_EQ(result.isDescriptionAvailable(), false);
    ASSERT_EQ(result.getResult(), 10);
    ASSERT_THROW(result.getDescription(), std::runtime_error);
}*/


int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
