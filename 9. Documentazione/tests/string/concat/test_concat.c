#include <CUnit/CUnit.h>

#include "test_concat.h"

#include "../../../libs/string/string.h"

void test_concat_with_input_string_null_returns_null()
{
    String* first_string = NULL;
    String* second_string = create_from_string("def");
}

void test_concat_with_string_to_concat_null_returns_null()
{
    String* first_string = create_from_string("abc");
    String* second_string = NULL;
}

void test_concat_with_input_string_and_string_to_concat_null_returns_null()
{
    String* first_string = NULL;
    String* second_string = NULL;

    String* result = concat(first_string, second_string);

    CU_ASSERT_PTR_NULL(result);
}

void test_concat_with_input_string_invalid_returns_null()
{
    String* first_string = create_from_string("abc");
    String* second_string = create_from_string("def");
    destroy(first_string);

    String* result = concat(first_string, second_string);

    CU_ASSERT_PTR_NULL(result);
}

void test_concat_with_string_to_concat_invalid_returns_null()
{
    String* first_string = create_from_string("abc");
    String* second_string = create_from_string("def");
    destroy(second_string);
    
    String* result = concat(first_string, second_string);
    
    CU_ASSERT_PTR_NULL(result);
}

void test_concat_with_input_string_and_string_to_concat_invalid_returns_null()
{
    String* first_string = create_from_string("abc");
    String* second_string = create_from_string("def");
    destroy(first_string);
    destroy(second_string);

    String* result = concat(first_string, second_string);

    CU_ASSERT_PTR_NULL(result);
}

void test_concat_with_returns_new_string()
{
    String* first_string = create_from_string("abc");
    String* second_string = create_from_string("def");

    String* result = concat(first_string, second_string);

    CU_ASSERT_PTR_NOT_NULL(result);
    CU_ASSERT_PTR_NOT_EQUAL(result, first_string);
    CU_ASSERT_PTR_NOT_EQUAL(result, second_string);
    CU_ASSERT_EQUAL(equals(result, create_from_string("abcdef")), 1);
}

CU_pSuite run_concat_suite()
{
    CU_pSuite suite = CU_add_suite("'concat' suite", NULL, NULL);

    if (suite == NULL) 
    {
        printf("Error in creating test suite 'concat'\n");
        return NULL;
    }

    CU_add_test(
        suite, 
        "concat with input string null should return null", 
        test_concat_with_input_string_null_returns_null
    );

    CU_add_test(
        suite, 
        "concat with string to concat null should return null", 
        test_concat_with_string_to_concat_null_returns_null
    );

    CU_add_test(
        suite, 
        "concat with input string and string to concat null should return null", 
        test_concat_with_input_string_and_string_to_concat_null_returns_null
    );

    CU_add_test(
        suite, 
        "concat with input string invalid should return null", 
        test_concat_with_input_string_invalid_returns_null
    );

    CU_add_test(
        suite, 
        "concat with string to concat invalid should return null", 
        test_concat_with_string_to_concat_invalid_returns_null
    );

    CU_add_test(
        suite, 
        "concat with input string and string to concat invalid should return null", 
        test_concat_with_input_string_and_string_to_concat_invalid_returns_null
    );

    CU_add_test(
        suite, 
        "concat should return new string", 
        test_concat_with_returns_new_string
    );

    return suite;
}