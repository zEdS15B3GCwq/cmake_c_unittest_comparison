#include "glib.h"
#include "utils.h"

typedef struct {
    int a;
} MyFixture

int b = 0;

static void
suite_a_setup(MyFixture *fixture, gconstpointer user_data)
{
    fixture->a = 1;
}

static void
test_identity_should_pass_setup(MyFixture *fixture, gconstpointer user_data)
{
    fixture->a = 2;
}


static void
test_identity_should_pass(MyFixture *fixture, gconstpointer user_data)
{
    // g_test_assert_
}

// void setUp(void) {
//     a = 1;
//     b[0] = 1; b[1] = 2; b[2] = 3; b[3] = 4; b[4] = 5;
//     c[0] = 0.1f; c[1] = 0.2f; c[2] = 0.3f; c[3] = 0.4f; c[4] = 0.5f;
//     d[0] = 4; d[1] = 4; d[2] = 4;
// }

// void tearDown(void) {
//     // pass
// }

// void test_identity_should_pass( void )
// {
//     TEST_ASSERT_TRUE( 40 == identity( 40 ) );
//     TEST_ASSERT_EQUAL_INT_MESSAGE( 1, identity( a ), "a should be 1 at this point" );
// }

// void test_identity_should_fail( void )
// {
//     TEST_ASSERT_TRUE_MESSAGE( 0 == identity( a ), "a should be 1 at this point" );
//     TEST_ASSERT_EQUAL_INT_MESSAGE( 99, identity( a ), "a is still 1 not 99" ); // asserts are apparently fatal, this is not shown
// }

// // repeats the skipped test from above
// void test_identity_should_fail_again( void )
// {
// //    TEST_ASSERT_EQUAL_INT_MESSAGE( 99, identity( a ), "a is still 1 not 99" );
//     TEST_ASSERT_EQUAL_INT_MESSAGE_M( 99, identity( a ), "a is still 1 not 99" );
// }

// void test_various_asserts_some_should_fail( void )
// {
//     TEST_ASSERT_EACH_EQUAL_INT_MESSAGE( 4, d, 3, "_EACH_EQUAL + _MESSAGE | should pass" );
//     TEST_ASSERT_EACH_EQUAL_INT_MESSAGE( 2, b, 5, "_EACH_EQUAL + _MESSAGE | should fail" ); // aborts here
//     const int i[] = {3, 3, 3, 3, 3};
//     TEST_ASSERT_INT_ARRAY_WITHIN( 2, i, b, 5 ); // pass
//     const float f[] = {0.1f, 0.2f, 0.3f, 0.4f, 0.6f};
//     TEST_ASSERT_EQUAL_FLOAT_ARRAY_MESSAGE(  f, c, 5, "last element is not 0.6 | should fail");
// }

// // repeats the skipped tests from above
// void test_various_asserts_some_should_fail_again( void )
// {
//     const int i[] = {3, 3, 3, 3, 3};
//     TEST_ASSERT_INT_ARRAY_WITHIN( 2, i, b, 5 ); // pass
//     float f[5] = {0.1f, 0.2f, 0.3f, 0.4f, 0.6f};
//     TEST_ASSERT_EQUAL_FLOAT_ARRAY_MESSAGE(  f, c, 5, "last element is not 0.6 | should fail");
// }

int main(int argc, char** argv)
{
    g_test_init(&argc, &argv, "");

    // g_test_add ("/my-object/test1", MyObjectFixture, "some-user-data",
    //             my_object_fixture_set_up, test_my_object_test1,
    //             my_object_fixture_tear_down);
    // // RUN_TEST(test_identity_should_pass);
    // RUN_TEST(test_identity_should_fail);
    // RUN_TEST(test_identity_should_fail_again);
    // RUN_TEST(test_various_asserts_some_should_fail);
    // RUN_TEST(test_various_asserts_some_should_fail_again);
    // return g_test_run();
    return 0;
}
