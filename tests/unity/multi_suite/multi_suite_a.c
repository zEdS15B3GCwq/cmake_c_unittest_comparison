#include "CUnit/CUnitCI.h"
#include "utils.h"
#include "multi_suite_a.h"

int a = 0;

CU_SUITE_SETUP() {
    a = 2;
    return CUE_SUCCESS;
}

CU_SUITE_TEARDOWN() {
    CU_ASSERT( a == 2 );
    a = 0;
    return CUE_SUCCESS;
}

static void test_a_identity_should_pass( void )
{
    CU_ASSERT( 2 == identity( a ) );
}

static void test_a_identity_should_fail( void )
{
    CU_ASSERT( 0 == identity( a ) );
}

void register_suite_a( void )
{
    CU_CI_DEFINE_SUITE( "multi suite a", __cu_suite_setup, __cu_suite_teardown, NULL, NULL );
	CUNIT_CI_TEST( test_a_identity_should_pass );
	CUNIT_CI_TEST( test_a_identity_should_fail );
}