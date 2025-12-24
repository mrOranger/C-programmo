#include <CUnit/CUnit.h>

#include "test_string_copy.h"

#include "../../../libs/string/string.h"

void test_string_copy_with_null_string_input_should_returns_null()
{
    void* input_string = NULL;
    size_t bytes_number = 0;

    void* string_result = string_copy(input_string, bytes_number);

    CU_ASSERT_PTR_NULL(string_result);
}

void test_string_copy_with_zero_number_bytes_returns_null()
{
    void* input_string = "ab123cd";
    size_t bytes_number = 0;

    void* string_result = string_copy(input_string, bytes_number);

    CU_ASSERT_PTR_NULL(string_result);
}

void test_string_copy_with_number_of_bytes_greater_than_string_length_returns_new_string()
{
    void* input_string = "ab123cd";
    size_t bytes_number = 7;

    void* string_result = string_copy(input_string, bytes_number);

    CU_ASSERT_PTR_NOT_NULL(string_result);
}

void test_string_copy_with_some_bytes_returns_new_string()
{
    void* input_string = "ab123cd";
    size_t bytes_number = 2;

    void* string_result = string_copy(input_string, bytes_number);

    CU_ASSERT_PTR_NOT_NULL(string_result);
}

CU_pSuite run_string_copy_suite()
{
    CU_pSuite suite = CU_add_suite("'string_copy' suite", NULL, NULL);

    if (suite == NULL)
    {
        printf("Error in creating test suite 'string_copy'\n");
        return NULL;
    }

    CU_add_test(
        suite, 
        "'string_copy' with null input string should return null",
        test_string_copy_with_null_string_input_should_returns_null
    );

    CU_add_test(
        suite, 
        "'string_copy' with zero number of bytes should return null", 
        test_string_copy_with_zero_number_bytes_returns_null
    );

    CU_add_test(
        suite, 
        "'string_copy' with number of bytes greater than input string length should return new string", 
        test_string_copy_with_number_of_bytes_greater_than_string_length_returns_new_string
    );

    CU_add_test(
        suite, 
        "'string_copy' with some bytes should return a new string", 
        test_string_copy_with_some_bytes_returns_new_string
    );

    return suite;    
}