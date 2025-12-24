#ifndef TEST_STRING_LENGTH_H
#define TEST_STRING_LENGTH_H

#include <CUnit/Basic.h>

void test_string_length_with_null_string_should_return_zero();
void test_string_length_with_string_with_one_char_should_return_one();
void test_string_length_with_regular_string_should_return_a_number();

CU_pSuite run_string_length_suite();


#endif