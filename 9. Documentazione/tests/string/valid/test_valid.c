#include <CUnit/CUnit.h>

#include "test_valid.h"

#include "../../../libs/string/string.h"

void test_valid_with_null_input_retuns_false()
{
    String* current_string = NULL;

    int8_t is_valid = valid(current_string);

    CU_ASSERT_EQUAL(is_valid, 0);
}

void test_valid_with_invalid_input_returns_false()
{
    String* current_string = create_empty();

    destroy(current_string);
    int8_t is_valid = valid(current_string);

    CU_ASSERT_EQUAL(is_valid, 0);
}

void test_valid_with_empty_string_input_returns_true()
{
    String* current_string = create_empty();

    int8_t is_valid = valid(current_string);

    CU_ASSERT_EQUAL(is_valid, 1);
}

void test_valid_with_valid_input_returns_true()
{
    String* current_string = create_from_string("1234567890");

    int8_t is_valid = valid(current_string);

    CU_ASSERT_EQUAL(is_valid, 1);
}

CU_pSuite run_valid_suite()
{
    CU_pSuite suite = CU_add_suite("'valid' suite", NULL, NULL);

    if (suite == NULL)
    {
        printf("Error in creating test suite 'valid'\n");
        return NULL;
    }

    CU_add_test(
        suite, 
        "'valid' with null input should return false", 
        test_valid_with_null_input_retuns_false    
    );

    CU_add_test(
        suite, 
        "'valid' with invalid input string should return false", 
        test_valid_with_empty_string_input_returns_true
    );

    CU_add_test(
        suite, 
        "'valid' with empty input string should return true", 
        test_valid_with_empty_string_input_returns_true
    ); 

    CU_add_test(
        suite, 
        "'valid' with valid input string should return true", 

        test_valid_with_valid_input_returns_true
    );

    return suite;
}

