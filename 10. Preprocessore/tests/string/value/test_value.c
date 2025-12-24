#include <CUnit/CUnit.h>

#include "test_value.h"

#include "../../../libs/string/string.h"

void test_value_with_null_input_returns_null()
{
    String* input_string = NULL;

    char* string = value(input_string);

    CU_ASSERT_PTR_NULL(string);
}

void test_value_with_invalid_string_returns_null()
{
    String* input_string = create_from_string("12345678890");

    destroy(input_string);
    char* string = value(input_string);

    CU_ASSERT_PTR_NULL(string);
}

void test_value_with_empty_string_returns_valid_pointer()
{
    String* input_string = create_empty();

    char* string = value(input_string);

    CU_ASSERT_PTR_NOT_NULL(string);
}

void test_value_with_regular_string_returns_valid_pointer()
{
    String* input_string = create_from_string("12345678890");

    char* string = value(input_string);

    CU_ASSERT_PTR_NOT_NULL(string);
}

CU_pSuite run_value_suite()
{
    CU_pSuite suite = CU_add_suite("'value' suite", NULL, NULL);

    if (suite == NULL)
    {
        printf("Error in creating test suite 'value'\n");
        return NULL;
    }

    CU_add_test(
        suite, 
        "'value' with null input should return null",
        test_value_with_null_input_returns_null
    );

    CU_add_test(
        suite, 
        "'value' with invalid input string should return null", 
        test_value_with_invalid_string_returns_null
    );

    CU_add_test(
        suite, 
        "'value' with empty string should return valid pointer", 
        test_value_with_empty_string_returns_valid_pointer
    );

    CU_add_test(
        suite, 
        "'value' with valid input string should return valid pointer1", 
        test_value_with_regular_string_returns_valid_pointer
    );

    return suite;
}

