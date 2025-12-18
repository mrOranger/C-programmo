#ifndef TEST_INCLUDES_H
#define TEST_INCLUDES_H

#include <CUnit/Basic.h>

void test_includes_with_input_string_null_returns_false();
void test_includes_with_search_string_null_returns_false();
void test_includes_with_input_and_search_string_null_returns_false();
void test_includes_with_input_string_invalid_returns_false();
void test_includes_with_search_string_invalid_returns_false();
void test_includes_with_input_and_search_string_invalid_returns_false();
void test_includes_with_input_string_smaller_then_search_string_returns_false();
void test_includes_returns_false();
void test_includes_returns_true();

CU_pSuite run_includes_suite();

#endif