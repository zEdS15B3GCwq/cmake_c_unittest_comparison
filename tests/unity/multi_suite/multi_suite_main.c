#include "CUnit/CUnitCI.h"

#include "multi_suite_a.h"
#include "multi_suite_b.h"

int main(int argc, char** argv) {
    register_suite_a();
    register_suite_b();
    return CU_CI_main(argc, argv);
}