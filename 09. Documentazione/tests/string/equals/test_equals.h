#ifndef TEST_EQUALS_H
#define TEST_EQUALS_H

#include <CUnit/Basic.h>

void test_equals_with_first_string_null_returns_false();
void test_equals_with_second_string_null_returns_false();
void test_equals_with_first_and_second_string_null_returns_false();
void test_equals_with_invalid_first_string_returns_false();
void test_equals_with_invalid_second_string_returns_false();
void test_equals_with_first_and_second_string_invalid_returns_false();
void test_equals_with_different_sizes_string_returns_false();
void test_equals_returns_false();
void test_equals_returns_true();

CU_pSuite run_equals_suite();

#endif
