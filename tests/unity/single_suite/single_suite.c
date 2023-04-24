#include "unity.h"

#ifdef UNITY_USE_COMMAND_LINE_ARGS
#include "unity_internals.h"
#endif

#include "utils.h"

#define TEST_ASSERT_EQUAL_INT_M( a, b ) TEST_ASSERT_EQUAL_INT_MESSAGE( (a), (b), #a " == " #b )
#define TEST_ASSERT_EQUAL_INT_MESSAGE_M( a, b, m ) TEST_ASSERT_EQUAL_INT_MESSAGE( (a), (b), #a " == " #b " | message: " m  )

int a = 0;
int b[5];
float c[5];
int d[3];

void setUp(void) {
    a = 1;
    b[0] = 1; b[1] = 2; b[2] = 3; b[3] = 4; b[4] = 5;
    c[0] = 0.1f; c[1] = 0.2f; c[2] = 0.3f; c[3] = 0.4f; c[4] = 0.5f;
    d[0] = 4; d[1] = 4; d[2] = 4;
}

void tearDown(void) {
    // pass
}

void test_identity_should_pass( void )
{
    TEST_ASSERT_TRUE( 40 == identity( 40 ) );
    TEST_ASSERT_EQUAL_INT_MESSAGE( 1, identity( a ), "a should be 1 at this point" );
}

void test_identity_should_fail( void )
{
    TEST_ASSERT_TRUE_MESSAGE( 0 == identity( a ), "a should be 1 at this point" );
    TEST_ASSERT_EQUAL_INT_MESSAGE( 99, identity( a ), "a is still 1 not 99" ); // asserts are apparently fatal, this is not shown
}

// repeats the skipped test from above
void test_identity_should_fail_again( void )
{
//    TEST_ASSERT_EQUAL_INT_MESSAGE( 99, identity( a ), "a is still 1 not 99" );
    TEST_ASSERT_EQUAL_INT_MESSAGE_M( 99, identity( a ), "a is still 1 not 99" );
}

void test_various_asserts_some_should_fail( void )
{
    TEST_ASSERT_EACH_EQUAL_INT_MESSAGE( 4, d, 3, "_EACH_EQUAL + _MESSAGE | should pass" );
    TEST_ASSERT_EACH_EQUAL_INT_MESSAGE( 2, b, 5, "_EACH_EQUAL + _MESSAGE | should fail" ); // aborts here
    const int i[] = {3, 3, 3, 3, 3};
    TEST_ASSERT_INT_ARRAY_WITHIN( 2, i, b, 5 ); // pass
    const float f[] = {0.1f, 0.2f, 0.3f, 0.4f, 0.6f};
    TEST_ASSERT_EQUAL_FLOAT_ARRAY_MESSAGE(  f, c, 5, "last element is not 0.6 | should fail");
}

// repeats the skipped tests from above
void test_various_asserts_some_should_fail_again( void )
{
    const int i[] = {3, 3, 3, 3, 3};
    TEST_ASSERT_INT_ARRAY_WITHIN( 2, i, b, 5 ); // pass
    float f[5] = {0.1f, 0.2f, 0.3f, 0.4f, 0.6f};
    TEST_ASSERT_EQUAL_FLOAT_ARRAY_MESSAGE(  f, c, 5, "last element is not 0.6 | should fail");
}

int main(int argc, char** argv)
{
    UNITY_BEGIN();
#ifdef UNITY_USE_COMMAND_LINE_ARGS
    if (UnityParseOptions(argc, argv)) return -1;
#endif
    RUN_TEST(test_identity_should_pass);
    RUN_TEST(test_identity_should_fail);
    RUN_TEST(test_identity_should_fail_again);
    RUN_TEST(test_various_asserts_some_should_fail);
    RUN_TEST(test_various_asserts_some_should_fail_again);
    return UNITY_END();
}
