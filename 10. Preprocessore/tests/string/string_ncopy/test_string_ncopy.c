#include <CUnit/CUnit.h>

#include "test_string_ncopy.h"

#include "../../../libs/string/string.h"

void test_string_ncopy_with_null_input_string_should_return_null()
{
    void* input_string = NULL;
    size_t starting_index = 0;
    size_t n_bytes = 0;

    void* string_copy = string_ncopy(input_string, n_bytes, starting_index);

    CU_ASSERT_PTR_NULL(string_copy);
    CU_ASSERT_EQUAL(string_length(string_copy), 0);
}

void test_string_ncopy_with_starting_index_greater_than_string_size_should_return_null()
{
    void* input_string = "ab123cd";
    size_t starting_index = 7;
    size_t n_bytes = 0;

    void* string_copy = string_ncopy(input_string, n_bytes, starting_index);

    CU_ASSERT_PTR_NULL(string_copy);
    CU_ASSERT_EQUAL(string_length(string_copy), 0);    
}

void test_string_ncopy_with_starting_index_greater_than_ending_index_string_should_return_null()
{
    void* input_string = "ab123cd";
    size_t starting_index = 2;
    size_t n_bytes = 0;

    void* string_copy = string_ncopy(input_string, n_bytes, starting_index);

    CU_ASSERT_PTR_NULL(string_copy);
    CU_ASSERT_EQUAL(string_length(string_copy), 0);
}

void test_string_ncopy_with_ending_index_greater_than_string_length_string_should_new_string()
{
    void* input_string = "ab123cd";
    size_t starting_index = 0;
    size_t n_bytes = 10;

    void* string_copy = string_ncopy(input_string, n_bytes, starting_index);

    CU_ASSERT_PTR_NOT_NULL(string_copy);
    CU_ASSERT_EQUAL(string_length(string_copy), string_length(input_string));
}

void test_string_ncopy_with_starting_index_equals_zero_should_new_string()
{
    void* input_string = "ab123cd";
    size_t starting_index = 0;
    size_t n_bytes = 2;

    void* string_copy = string_ncopy(input_string, n_bytes, starting_index);

    CU_ASSERT_PTR_NOT_NULL(string_copy);
    CU_ASSERT_EQUAL(string_length(string_copy), 2);
}

void test_string_ncopy_should_new_string()
{
    void* input_string = "ab123cd";
    size_t starting_index = 2;
    size_t n_bytes = 3;

    void* string_copy = string_ncopy(input_string, n_bytes, starting_index);

    CU_ASSERT_PTR_NOT_NULL(string_copy);
    CU_ASSERT_EQUAL(string_length(string_copy), 3);
}

CU_pSuite run_string_ncopy_suite()
{
    CU_pSuite suite = CU_add_suite("'string_ncopy' suite", NULL, NULL);

    if (suite == NULL)
    {
        printf("Error in creating test suite 'string_ncopy'\n");
        return NULL;
    }

    CU_add_test(
        suite, 
        "'string_ncopy' null input string should return null",
        test_string_ncopy_with_null_input_string_should_return_null
    );

    CU_add_test(
        suite, 
        "'string_ncopy' with starting index greater than string index should return null",
        test_string_ncopy_with_starting_index_greater_than_string_size_should_return_null
    );

    CU_add_test(
        suite, 
        "'string_ncopy' with starting index greater than ending index should return null",
        test_string_ncopy_with_starting_index_greater_than_ending_index_string_should_return_null
    );

    CU_add_test(
        suite, 
        "'string_ncopy' with ending index greater than string length should return new string",
        test_string_ncopy_with_ending_index_greater_than_string_length_string_should_new_string
    );

    CU_add_test(
        suite, 
        "'string_ncopy' with starting index equals zero should return a new string",
        test_string_ncopy_with_starting_index_equals_zero_should_new_string
    );

    CU_add_test(
        suite, 
        "'string_ncopy' should return a new string", 
        test_string_ncopy_should_new_string
    );

    return suite;
}