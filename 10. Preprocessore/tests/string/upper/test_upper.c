#include <CUnit/CUnit.h>

#include "test_upper.h"

#include "../../../libs/string/string.h"

void test_upper_with_input_string_null_returns_null()
{
    String* input_string = NULL;
    
    String* upper_string = upper(input_string);

    CU_ASSERT_PTR_NULL(upper_string);
}

void test_upper_with_input_string_not_valid_returns_null()
{
    String* input_string = create_from_string("abcd");
    destroy(input_string);
    
    String* upper_string = upper(input_string);

    CU_ASSERT_PTR_NULL(upper_string);
}

void test_upper_returns_new_string()
{
    String* input_string = create_from_string("abcd");
    
    String* upper_string = upper(input_string);

    CU_ASSERT_PTR_NOT_NULL(upper_string);
    CU_ASSERT_PTR_NOT_EQUAL(input_string, upper_string);
    CU_ASSERT_EQUAL(equals(upper_string, create_from_string("ABCD")), 1);
}

CU_pSuite run_upper_string_suite()
{
    CU_pSuite suite = CU_add_suite("'upper' suite", NULL, NULL);

    if (suite == NULL) 
    {
        printf("Error in creating test suite 'upper'\n");
        return NULL;
    }

    CU_add_test(
        suite, 
        "upper with input string null should return null", 
        test_upper_with_input_string_null_returns_null
    );

    CU_add_test(
        suite, 
        "upper with input string not valid should return null", 
        test_upper_with_input_string_not_valid_returns_null
    );

    CU_add_test(
        suite, 
        "upper should return new string", 
        test_upper_returns_new_string
    );

    return suite;
}