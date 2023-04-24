#include "unity.h"
#include "unity_fixture.h"
#include "utils.h"

TEST_GROUP(multi_suite_a)

int a = 0;

TEST_SETUP(multi_suite_a) {
    a = 2;
}

TEST_TEAR_DOWN(multi_suite_a) {
}

TEST(multi_suite_a, test_a_identity_should_pass)
{
    TEST_ASSERT_TRUE( 2 == identity( a ) );
}

TEST(multi_suite_a, test_a_identity_should_fail)
{
    TEST_ASSERT_TRUE( 0 == identity( a ) );
}

TEST_GROUP_RUNNER(multi_suite_a)
{
    RUN_TEST_CASE(multi_suite_a, test_a_identity_should_pass);
    RUN_TEST_CASE(multi_suite_a, test_a_identity_should_fail);
}