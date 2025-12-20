#ifndef TEST_UPPER_H
#define TEST_UPPER_H

#include <CUnit/Basic.h>

void test_upper_with_input_string_null_returns_null();
void test_upper_with_input_string_not_valid_returns_null();
void test_upper_returns_new_string();

CU_pSuite run_upper_string_suite();

#endif