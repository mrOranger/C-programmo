#ifndef TEST_CONCAT_H
#define TEST_CONCAT_H

#include <CUnit/Basic.h>

void test_concat_with_input_string_null_returns_null();
void test_concat_with_string_to_concat_null_returns_null();
void test_concat_with_input_string_and_string_to_concat_null_returns_null();
void test_concat_with_input_string_invalid_returns_null();
void test_concat_with_string_to_concat_invalid_returns_null();
void test_concat_with_input_string_and_string_to_concat_invalid_returns_null();
void test_concat_with_returns_new_string();

CU_pSuite run_concat_suite();

#endif