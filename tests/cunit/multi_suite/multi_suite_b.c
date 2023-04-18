#include "CUnit/CUnitCI.h"
#include "utils.h"
#include "multi_suite_b.h"

static void test_b_identity_should_pass( void )
{
    CU_ASSERT_FATAL( 40 == identity( 40 ) );
}

static void test_b_identity_should_fail( void )
{
    CU_ASSERT_FATAL( 2 == identity( 2 ) );
    CU_ASSERT_FATAL( 2 == identity( 1 ) );
}

void register_suite_b( void )
{
    CU_CI_DEFINE_SUITE( "multi suite b", NULL, NULL, NULL, NULL );
	CUNIT_CI_TEST( test_b_identity_should_pass );
	CUNIT_CI_TEST( test_b_identity_should_fail );
}
