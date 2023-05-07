#include "glib.h"
#include "utils.h"
#include "multi_suite_b.h"

static void test_b_identity_should_pass( void )
{
    g_assert_true( 40 == identity( 40 ) );
}

static void test_b_identity_should_fail( void )
{
    g_assert_cmpint( 2, ==, identity( 2 ) );
    g_assert_cmpint( 2, ==, identity( 1 ) );
}

void register_suite_b( void )
{
    g_test_add_func( "/multi_suite/suite_b/test_b_identity_should_pass", test_b_identity_should_pass );
    g_test_add_func( "/multi_suite/suite_b/test_b_identity_should_fail", test_b_identity_should_fail );
}
