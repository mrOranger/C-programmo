#ifndef TEST_VALUE_H
#define TEST_VALUE_H

#include <CUnit/CUnit.h>

void test_value_with_null_input_returns_null();
void test_value_with_invalid_string_returns_null();
void test_value_with_empty_string_returns_valid_pointer();
void test_value_with_regular_string_returns_valid_pointer();

CU_pSuite run_value_suite();

#endif
