#include "glib.h"
#include "utils.h"
#include "multi_suite_a.h"

int b = 0;

static void
test_a_setup( TestAFixture *fixture, gconstpointer user_data )
{
    fixture->a = 1;
}

static void test_a_fixture_should_pass( TestAFixture *fixture, const int *user_data )
{
    g_assert_cmpint( fixture->a, ==, 1 );
    g_assert_cmpint( *user_data, ==, 2 );
}

static void test_a_identity_should_fail( TestAFixture *fixture, const int *user_data )
{
    g_assert_cmpint( 0, ==, identity( 2 ) );
    g_assert_cmpint( fixture->a, <, 1 );
    g_assert_null( user_data );
    g_assert_cmpint( 0, ==, *user_data );
}

void register_suite_a( void )
{
    b = 2;
    g_test_add( "/multi_suite/suite_a/test_a_fixture_should_pass",
                TestAFixture,
                &b,
                test_a_setup,
                test_a_fixture_should_pass,
                NULL );

    g_test_add( "/multi_suite/suite_a/test_a_identity_should_fail",
                TestAFixture,
                &b,
                test_a_setup,
                test_a_identity_should_fail,
                NULL );
}
