#ifndef TEST_STRING_COPY_H
#define TEST_STRING_COPY_H

#include <CUnit/Basic.h>

void test_string_copy_with_null_string_input_should_returns_null();
void test_string_copy_with_zero_number_bytes_returns_null();
void test_string_copy_with_number_of_bytes_greater_than_string_length_returns_new_string();
void test_string_copy_with_some_bytes_returns_new_string();

CU_pSuite run_string_copy_suite();

#endif