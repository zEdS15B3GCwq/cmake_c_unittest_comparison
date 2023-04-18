#include "CUnit/CUnitCI.h"

#include <utils.h>

static void test_Identity_should_Pass1( void )
{
    CU_ASSERT_FATAL( 40 == identity( 40 ) );
    CU_ASSERT_FATAL( 1 == identity( 1 ) );
}


static void test_Identity_should_Pass2( void )
{
    CU_ASSERT_FATAL( 200 == identity( 200 ) );
}

CUNIT_CI_RUN( "cunit_suite1",
    CUNIT_CI_TEST( test_Identity_should_Pass1 ),
    CUNIT_CI_TEST( test_Identity_should_Pass2 ) );
