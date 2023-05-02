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
}

static void
test_func_only_fail_printf_should_show( void )
{
    g_test_fail_printf("SHOWN g_test_fail_printf test\n");
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

    return g_test_run ();
}