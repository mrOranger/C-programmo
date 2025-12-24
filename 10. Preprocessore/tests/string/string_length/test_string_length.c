#include <CUnit/CUnit.h>

#include "test_string_length.h"

#include "../../../libs/string/string.h"

void test_string_length_with_null_string_should_return_zero()
{
    void* input_string = NULL;

    size_t length = string_length(input_string);

    CU_ASSERT_EQUAL(length, 0);
}

void test_string_length_with_string_with_one_char_should_return_one()
{
    void* input_string = "c";

    size_t length = string_length(input_string);

    CU_ASSERT_EQUAL(length, 1);
}

void test_string_length_with_regular_string_should_return_a_number()
{
    void* input_string = "abcd";

    size_t length = string_length(input_string);

    CU_ASSERT_EQUAL(length, 4);
}

CU_pSuite run_string_length_suite()
{
    CU_pSuite suite = CU_add_suite("'string_length' suite", NULL, NULL);

    if (suite == NULL)
    {
        printf("Error in creating test suite 'string_length'\n");
        return NULL;
    }

    CU_add_test(
        suite, 
        "'string_length' with null input should return zero", 
        test_string_length_with_null_string_should_return_zero
    );

    CU_add_test(
        suite, 
        "'string_length' with input string having one char should return one", 
        test_string_length_with_string_with_one_char_should_return_one
    );

    CU_add_test(
        suite, 
        "'string_length' with regular string should return a number", 
        test_string_length_with_regular_string_should_return_a_number
    );

    return suite;
}