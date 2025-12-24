#ifndef TEST_DESTROY_H
#define TEST_DESTROY_H

#include <CUnit/Basic.h>

void test_destroy_with_string_null_returns_null();
void test_destroy_with_string_invalid_returns_null();
void test_destroy_success();

CU_pSuite run_destroy_suite();

#endif