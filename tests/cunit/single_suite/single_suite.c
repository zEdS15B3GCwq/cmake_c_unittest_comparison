#include "CUnit/CUnitCI.h"
#include "utils.h"

int a = 0;

CU_SUITE_SETUP() {
    a = 1;
    return CUE_SUCCESS;
}

CU_SUITE_TEARDOWN() {
    CU_ASSERT_FATAL( a == 1 );
    a = 0;
    return CUE_SUCCESS;
}

void test_identity_should_pass( void )
{
    CU_ASSERT_FATAL( 40 == identity( 40 ) );
    CU_ASSERT_FATAL( 1 == identity( a ) );
}


void test_identity_should_fail( void )
{
    CU_ASSERT_FATAL( 0 == identity( a ) );
}

CUNIT_CI_RUN( "cunit_single_suite",
    CUNIT_CI_TEST( test_identity_should_pass ),
    CUNIT_CI_TEST( test_identity_should_fail ) );
