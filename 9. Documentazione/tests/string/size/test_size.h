#ifndef TEST_SIZE_H
#define TEST_SIZE_H

#include <CUnit/Basic.h>

void test_size_with_null_input_retuns_zero();
void test_size_with_invalid_input_returns_zero();
void test_size_with_empty_string_input_returns_zero();
void test_size_with_valid_input_returns_right_size();

CU_pSuite run_size_suite();

#endif
