#ifndef TEST_INDEX_OF_H
#define TEST_INDEX_OF_H

#include <CUnit/Basic.h>

void test_index_of_with_input_string_null_returns_false();
void test_index_of_with_search_string_null_returns_false();
void test_index_of_with_input_and_search_string_null_returns_false();
void test_index_of_with_input_string_invalid_returns_false();
void test_index_of_with_search_string_invalid_returns_false();
void test_index_of_with_input_and_search_string_invalid_returns_false();
void test_index_of_with_input_string_smaller_then_search_string_returns_false();
void test_index_of_returns_negative_number();
void test_index_of_returns_right_index();

CU_pSuite run_index_of_suite();

#endif