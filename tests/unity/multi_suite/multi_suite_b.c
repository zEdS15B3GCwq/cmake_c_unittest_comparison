#include "unity.h"
#include "unity_fixture.h"
#include "utils.h"

TEST_GROUP(multi_suite_b)

TEST(multi_suite_b, test_b_identity_should_pass)
{
    TEST_ASSERT_EQUAL_INT( 40, identity( 40 ) );
}

TEST(multi_suite_b, test_b_identity_should_fail)
{
    TEST_ASSERT_EQUAL_INT( 2, identity( 2 ) );
    TEST_ASSERT_EQUAL_INT( 2, identity( 1 ) );
}

TEST_GROUP_RUNNER(multi_suite_b)
{
    RUN_TEST_CASE(multi_suite_b, test_b_identity_should_pass);
    RUN_TEST_CASE(multi_suite_b, test_b_identity_should_fail);
}
