#include <glib.h>
#include "utils.h"

typedef struct {
    int a;
} MyFixture;

static void
setup( MyFixture *fixture, gconstpointer user_data )
{
    g_print("setup\n");
    fixture->a = 1;
}

static void
teardown( MyFixture *fixture, gconstpointer user_data )
{
    g_print("tear down\n");
}

static void
test_should_pass( MyFixture *fixture, gconstpointer user_data )
{
    g_test_summary("this test should pass");
    g_test_bug("//test/should/pass");
    g_print("test_should_pass\n");
    g_assert_nonnull(fixture);
    g_assert_cmpint(fixture->a, ==, 1);
    g_assert_cmpint(1, ==, identity(1));
    g_assert_cmpint(fixture->a, ==, identity(fixture->a));
}

static void
test_func_only_multi_fail( void )
{
    g_assert_true(FALSE);
    g_test_fail_printf("NOT SHOWN g_test_fail_printf test\n");
    g_assert_cmpint(2, <, identity(1));
    int b = 3;
    g_assert_cmpint(4, ==, identity(b));
}

static void
test_func_only_fail_printf_should_show( void )
{
    g_test_fail_printf("SHOWN g_test_fail_printf test\n");
}

static void
test_trap_failure_and_stdout( const int *user_data )
{
    const gchar *s = "**stdout from subprocess**";
    if (g_test_subprocess()) {
        g_print(s);
        g_assert_cmpint( 2, ==, *user_data );
        return;
    }
    g_test_trap_subprocess( NULL, 0, G_TEST_SUBPROCESS_DEFAULT ); // G_TEST_SUBPROCESS_INHERIT_STDOUT );
    g_test_trap_assert_failed();
    g_test_trap_assert_stdout(s);
}

static void
test_string_array_should_fail( const char **expected )
{
    g_test_summary("this string array test will fail");
    g_test_bug("//test/should/fail");
    const char *data[] = { "one", "too", "three", NULL };
    g_assert_cmpstrv( data, expected );
}

int
main (int argc, char *argv[])
{
    g_test_init (&argc, &argv, NULL);
    g_test_set_nonfatal_assertions ();

    g_test_add ("/single_suite/test_should_pass", MyFixture, "some-user-data",
                setup, test_should_pass, teardown);

    g_test_add_func("/single_suite/test_func_only_multi_fail", test_func_only_multi_fail);
    g_test_add_func("/single_suite/test_func_only_fail_printf_should_show", test_func_only_fail_printf_should_show);

    // int data = 3;
    // g_test_add_data_func( "/single_suite/trap_fail_stdout", &data, test_trap_failure_and_stdout );

    const char *expected[] = { "one", "two", "three", NULL };
    g_test_add_data_func( "/single_suite/str_array_fail", expected, test_string_array_should_fail );

    return g_test_run();
}