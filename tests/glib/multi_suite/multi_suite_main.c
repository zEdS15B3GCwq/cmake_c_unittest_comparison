#include "glib.h"

#include "multi_suite_a.h"
#include "multi_suite_b.h"

int main(int argc, char** argv) {
    g_test_init (&argc, &argv, NULL);
    g_test_set_nonfatal_assertions ();

    register_suite_a();
    register_suite_b();

    return g_test_run();
}