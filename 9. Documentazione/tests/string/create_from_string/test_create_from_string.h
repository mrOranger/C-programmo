#ifndef TEST_CREATE_STRING_H
#define TEST_CREATE_STRING_H

#include <CUnit/Basic.h>

void test_create_from_string_with_null_returns_null();
void test_create_from_string_with_empty_string_returns_empty_string();
void test_create_from_longer_string_returns_null();
void test_create_from_string_returns_new_string();

CU_pSuite run_create_from_string_suite();

#endif
