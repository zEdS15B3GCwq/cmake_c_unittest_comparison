#include "CUnit/CUnitCI.h"
#include "CUnit/CUnit.h"
#include "utils.h"

int a = 0;

CU_SUITE_SETUP() {
    a = 1;
    return CUE_SUCCESS;
}

CU_SUITE_TEARDOWN() {
    CU_ASSERT( a == 1 );
    a = 0;
    return CUE_SUCCESS;
}

void test_identity_should_pass( void )
{
    CU_ASSERT( 40 == identity( 40 ) );
    CU_ASSERT_EQUAL( 1, identity( a ) );
}


void test_identity_should_fail( void )
{
    CU_ASSERT( 0 == identity( a ) );
    CU_ASSERT_EQUAL( 99, identity( a ) );
}

CUNIT_CI_RUN( "cunit_single_suite",
    CUNIT_CI_TEST( test_identity_should_pass ),
    CUNIT_CI_TEST( test_identity_should_fail ) );
