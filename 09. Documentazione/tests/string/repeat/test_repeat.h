#ifndef TEST_REPEAT_H
#define TEST_REPEAT_H

#include <CUnit/Basic.h>

void test_repeat_with_input_string_null_returns_null();
void test_repeat_with_input_string_invalid_returns_null();
void test_repeat_with_input_repetitions_zero_returns_empty_string();
void test_repeat_returns_new_string();

CU_pSuite run_repeat_suite();

#endif