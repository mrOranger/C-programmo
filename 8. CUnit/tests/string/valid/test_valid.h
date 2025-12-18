#ifndef TEST_VALID_H
#define TEST_VALID_H

#include <CUnit/Basic.h>

void test_valid_with_null_input_retuns_false();
void test_valid_with_invalid_input_returns_false();
void test_valid_with_empty_string_input_returns_true();
void test_valid_with_valid_input_returns_true();

CU_pSuite run_valid_suite();

#endif
