#ifndef TEST_LOWER_H
#define TEST_LOWER_H

#include <CUnit/Basic.h>

void test_lower_with_input_string_null_returns_null();
void test_lower_with_input_string_not_valid_returns_null();
void test_lower_returns_new_string();

CU_pSuite run_lower_string_suite();

#endif