#include "CUnit/CUnitCI.h"

#include <module_a.h>

static void test_AverageThreeBytes_should_AverageMidRangeValues( void )
{
    CU_ASSERT_FATAL( 40 == AverageThreeBytes( 30, 40, 50 ) );
    CU_ASSERT_FATAL( 40 == AverageThreeBytes( 10, 70, 40 ) );
    CU_ASSERT_FATAL( 33 == AverageThreeBytes( 33, 33, 33 ) );
}

static void test_AverageThreeBytes_should_AverageHighValues( void )
{
    CU_ASSERT_FATAL( 80 == AverageThreeBytes( 70, 80, 90 ) );
    CU_ASSERT_FATAL( 124 == AverageThreeBytes( 127, 127, 127 ) );
    CU_ASSERT_FATAL( 84 == AverageThreeBytes( 0, 126, 126 ) );
}

CUNIT_CI_RUN( "my-suite",
    CUNIT_CI_TEST( test_AverageThreeBytes_should_AverageMidRangeValues ),
    CUNIT_CI_TEST( test_AverageThreeBytes_should_AverageHighValues ) );
