#include "unity_fixture.h"

static void RunAllTests(void)
{
  RUN_TEST_GROUP(multi_suite_a);
  RUN_TEST_GROUP(multi_suite_b);
}

int main(int argc, const char * argv[])
{
  return UnityMain(argc, argv, RunAllTests);
}