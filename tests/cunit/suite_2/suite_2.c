#include "CUnit/CUnitCI.h"

#include <utils.h>

static void test_Identity_should_Pass( void )
{
    CU_ASSERT_FATAL( 2 == identity( 2 ) );
}

static void test_Identity_should_Fail( void )
{
    CU_ASSERT_FATAL( 40 == identity( 41 ) );
    CU_ASSERT_FATAL( 1 == identity( 2 ) );
}

CUNIT_CI_RUN( "cunit_suite2",
    CUNIT_CI_TEST( test_Identity_should_Pass ),
    CUNIT_CI_TEST( test_Identity_should_Fail ) );
