#include <stdlib.h>
#include <assert.h>

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <CUnit/TestDB.h>
#include <CUnit/Console.h>

#include "testmod.h"

int seed = 1024;


void test_testmod_add_int () {
	int a = rand_r (&seed);
	int b = rand_r (&a);

	int res = testmod_add_int (a, b);

	CU_ASSERT_EQUAL (res, a + b);
}

CU_TestInfo testcase [] = {
	{"test_testmod_add_int", test_testmod_add_int},
	CU_TEST_INFO_NULL
};

int suite_success_init (void) {
	return 0;
}

int suite_success_clean (void) {
	return 0;
}


CU_SuiteInfo suites [] = {
	{"testSuite1", suite_success_init, suite_success_clean, NULL, NULL, testcase},
	{"testSuite2", suite_success_init, suite_success_clean, NULL, NULL, testcase},
	CU_SUITE_INFO_NULL
};

void add_tests () {
	assert (NULL != CU_get_registry ());
	assert (! CU_is_test_running ());

	if (CUE_SUCCESS != CU_register_suites (suites)) 
		exit (EXIT_FAILURE);
}

int main (int argc, char* argv []) {
	if (CU_initialize_registry ()) {
		fprintf (stderr, "Initializing of Test Registry failure.");
		exit (EXIT_FAILURE);
	} else
		add_tests ();

	CU_basic_set_mode (CU_BRM_NORMAL);
	CU_basic_run_tests ();

	CU_cleanup_registry ();
	return CU_get_error ();
}



