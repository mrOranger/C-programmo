#include <CUnit/CUnit.h>

#include "test_size.h"

#include "../../../libs/string/string.h"

void test_size_with_null_input_retuns_zero()
{
    String* current_string = NULL;

    size_t string_size = size(current_string);

    CU_ASSERT_EQUAL(string_size, 0);
}

void test_size_with_invalid_input_returns_zero()
{
    String* current_string = create_empty();
    destroy(current_string);

    size_t string_size = size(current_string);

    CU_ASSERT_EQUAL(string_size, 0);
}

void test_size_with_empty_string_input_returns_zero()
{
    String* current_string = create_from_string("");

    size_t string_size = size(current_string);

    CU_ASSERT_EQUAL(string_size, 0);
}

void test_size_with_valid_input_returns_right_size()
{
    String* current_string = create_from_string("1234567890");

    size_t string_size = size(current_string);

    CU_ASSERT_EQUAL(string_size, 10);
}

CU_pSuite run_size_suite()
{
    CU_pSuite suite = CU_add_suite("'size' suite", NULL, NULL);

    if (suite == NULL)
    {
        printf("Error in creating test suite 'size'\n");
        return NULL;
    }

    CU_add_test(
        suite, 
        "'size' with null input should return zero", 
        test_size_with_null_input_retuns_zero
    );

    CU_add_test(
        suite, 
        "'size' with invalid input string should return zero", 
        test_size_with_invalid_input_returns_zero
    );

    CU_add_test(
        suite, 
        "'size' with empty string should return 0", 
        test_size_with_empty_string_input_returns_zero
    );

    CU_add_test(
        suite, 
        "'size' with valid input string should return right size", 
        test_size_with_valid_input_returns_right_size
    );

    return suite;
}
