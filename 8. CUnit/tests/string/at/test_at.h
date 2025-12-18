#ifndef TEST_AT_H
#define TEST_AT_H

#include <CUnit/Basic.h>

void test_at_with_input_string_null_returns_null();
void test_at_with_input_string_not_valid_returns_null();
void test_at_with_invalid_index_returns_null();
void test_at_returns_string();

CU_pSuite run_at_string_suite();

#endif