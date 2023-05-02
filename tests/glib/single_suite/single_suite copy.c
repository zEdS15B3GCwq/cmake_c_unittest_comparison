#include "glib.h"
#include "utils.h"

typedef struct {
    guint a;
} MyFixture;

static void
test_identity_should_pass_setup(MyFixture *fixture, gconstpointer user_data)
{
    g_print("1\n");
    fixture->a = 1;
}

static void
test_identity_should_pass_teardown(MyFixture *fixture, gconstpointer user_data)
{
    g_print("2\n");
    // nothing to do here
}

static void
test_identity_should_pass(MyFixture *fixture, gconstpointer user_data)
{
    g_print("3\n");
    g_assert_true(1 == identity(1));
    g_print("4\n");
    g_assert_cmpint(1, <, identity(2));
    g_print("5\n");
    g_assert_cmpuint(1, ==, identity(fixture->a));
    g_print("6\n");
    g_assert_cmpstr("user-data", ==, user_data);
    g_print("7\n");
    g_assert_cmpuint(1, ==, fixture->a);
    g_print("8\n");
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

static void test(void) { g_print("test\n"); }

static void setup(MyFixture *f, gconstpointer d) { g_print("setup\n"); }
static void teardown(MyFixture *f, gconstpointer d) { g_print("tear down\n"); }
static void testf(MyFixture *f, gconstpointer d) { g_print("testf\n"); }

int main(int argc, char** argv)
{
    g_test_init(&argc, &argv, "");
    g_print("9\n");

    // g_test_add( "/single_suite/test_identity_should_pass_setup", MyFixture, "user-data", test_identity_should_pass_setup, test_identity_should_pass, test_identity_should_pass_teardown );
    // g_test_add( "/a/b", MyFixture, NULL, NULL, NULL, NULL );
    g_test_add_func("/a/b", test);
    g_print("10\n");

    g_test_add( "/a/c", MyFixture, NULL, setup, testf, teardown);
    g_print("11\n");
    return g_test_run();
    // return 0;
}
