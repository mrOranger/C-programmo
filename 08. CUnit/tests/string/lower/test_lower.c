#include <CUnit/CUnit.h>

#include "test_lower.h"

#include "../../../libs/string/string.h"

void test_lower_with_input_string_null_returns_null()
{
    String* input_string = NULL;
    
    String* lower_string = lower(input_string);

    CU_ASSERT_PTR_NULL(lower_string);
}

void test_lower_with_input_string_not_valid_returns_null()
{
    String* input_string = create_from_string("ABCD");
    destroy(input_string);
    
    String* lower_string = lower(input_string);

    CU_ASSERT_PTR_NULL(lower_string);
}

void test_lower_returns_new_string()
{
    String* input_string = create_from_string("ABCD");
    
    String* lower_string = lower(input_string);

    CU_ASSERT_PTR_NOT_NULL(lower_string);
    CU_ASSERT_PTR_NOT_EQUAL(input_string, lower_string);
    CU_ASSERT_EQUAL(equals(lower_string, create_from_string("abcd")), 1);
}

CU_pSuite run_lower_string_suite()
{
    CU_pSuite suite = CU_add_suite("'lower' suite", NULL, NULL);

    if (suite == NULL) 
    {
        printf("Error in creating test suite 'lower'\n");
        return NULL;
    }

    CU_add_test(
        suite, 
        "lower with input string null should return null", 
        test_lower_with_input_string_null_returns_null
    );

    CU_add_test(
        suite, 
        "lower with input string not valid should return null", 
        test_lower_with_input_string_not_valid_returns_null
    );

    CU_add_test(
        suite, 
        "lower should return new string", 
        test_lower_returns_new_string
    );

    return suite;
}