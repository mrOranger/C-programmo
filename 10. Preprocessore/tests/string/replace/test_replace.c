#include <CUnit/CUnit.h>

#include "test_replace.h"

#include "../../../libs/string/string.h"

void test_replace_with_null_string_to_replace_returns_null()
{
    String* input_string = NULL;
    String* pattern = create_empty();
    String* string_to_replace = create_empty();

    String* updated_string = replace(input_string, pattern, string_to_replace);

    CU_ASSERT_PTR_NULL(updated_string);
}

void test_replace_with_invalid_string_to_replace_returns_null()
{
    String* input_string = NULL;
    String* pattern = create_empty();
    String* string_to_replace = create_empty();
    destroy(input_string);

    String* updated_string = replace(input_string, pattern, string_to_replace);

    CU_ASSERT_PTR_NULL(updated_string);
}

void test_replace_with_empty_string_to_replace_returns_null()
{
    String* input_string = create_empty();
    String* pattern = create_empty();
    String* string_to_replace = create_empty();

    String* updated_string = replace(input_string, pattern, string_to_replace);

    CU_ASSERT_PTR_NULL(updated_string);
}

void test_replace_with_valid_string_to_replace_and_null_replace_pattern_returns_null()
{
    String* input_string = create_from_string("AB123CD");
    String* pattern = NULL;
    String* string_to_replace = create_empty();

    String* updated_string = replace(input_string, pattern, string_to_replace);

    CU_ASSERT_PTR_NULL(updated_string);
}

void test_replace_with_valid_string_to_replace_and_invalid_replace_pattern_returns_null()
{
    String* input_string = create_from_string("AB123CD");
    String* pattern = create_from_string("123");
    String* string_to_replace = create_empty();
    destroy(pattern);

    String* updated_string = replace(input_string, pattern, string_to_replace);

    CU_ASSERT_PTR_NULL(updated_string);
}

void test_replace_with_valid_string_to_replace_and_empty_replace_pattern_returns_returns_input_string()
{
    String* input_string = create_from_string("AB123CD");
    String* pattern = create_empty();
    String* string_to_replace = create_empty();

    String* updated_string = replace(input_string, pattern, string_to_replace);

    CU_ASSERT_PTR_NOT_NULL(updated_string);
    CU_ASSERT_EQUAL(equals(input_string, create_from_string("AB123CD")), 1);
}

void test_replace_with_valid_string_to_replace_and_valid_replace_pattern_and_null_replace_returns_null()
{
    String* input_string = create_from_string("AB123CD");
    String* pattern = create_empty();
    String* string_to_replace = NULL;

    String* updated_string = replace(input_string, pattern, string_to_replace);

    CU_ASSERT_PTR_NULL(updated_string);
}

void test_replace_with_valid_string_to_replace_and_valid_replace_pattern_and_invalid_replace_returns_null()
{
    String* input_string = create_from_string("AB123CD");
    String* pattern = create_from_string("123");
    String* string_to_replace = create_from_string("AAA");
    destroy(pattern);

    String* updated_string = replace(input_string, pattern, string_to_replace);

    CU_ASSERT_PTR_NULL(updated_string);
}

void test_replace_with_valid_string_to_replace_and_valid_replace_pattern_and_empty_replace_returns_new_string()
{
    String* input_string = create_from_string("AB123CD");
    String* pattern = create_from_string("123");
    String* string_to_replace = create_empty();

    String* updated_string = replace(input_string, pattern, string_to_replace);

    CU_ASSERT_PTR_NOT_NULL(updated_string);
    CU_ASSERT_EQUAL(equals(updated_string, create_from_string("AB123CD")), 1);
}

void test_replace_with_valid_string_to_replace_and_unknown_replace_pattern_returns_new_string()
{
    String* input_string = create_from_string("AB123CD");
    String* pattern = create_from_string("456");
    String* string_to_replace = create_from_string("AAA");

    String* updated_string = replace(input_string, pattern, string_to_replace);

    CU_ASSERT_PTR_NOT_NULL(updated_string);
    CU_ASSERT_EQUAL(equals(updated_string, create_from_string("AB123CD")), 1);
}

void test_replace_with_valid_string_to_replace_and_valid_replace_pattern_returns_new_string()
{
    String* input_string = create_from_string("AB123CD");
    String* pattern = create_from_string("123");
    String* string_to_replace = create_from_string("AAA");

    String* updated_string = replace(input_string, pattern, string_to_replace);

    CU_ASSERT_PTR_NOT_NULL(updated_string);
    CU_ASSERT_EQUAL(equals(updated_string, create_from_string("ABAAACD")), 1);
}

void test_replace_with_valid_string_to_replace_and_valid_replace_pattern_returns_new_shorter_string()
{
    String* input_string = create_from_string("AB123CD");
    String* pattern = create_from_string("123");
    String* string_to_replace = create_from_string("X");

    String* updated_string = replace(input_string, pattern, string_to_replace);

    CU_ASSERT_PTR_NOT_NULL(updated_string);
    CU_ASSERT_EQUAL(equals(updated_string, create_from_string("ABXCD")), 1);
}

void test_replace_with_valid_string_to_replace_and_valid_replace_pattern_returns_new_longer_string()
{
    String* input_string = create_from_string("AB123CD");
    String* pattern = create_from_string("123");
    String* string_to_replace = create_from_string("XXXXXXXXXX");

    String* updated_string = replace(input_string, pattern, string_to_replace);

    CU_ASSERT_PTR_NOT_NULL(updated_string);
    CU_ASSERT_EQUAL(equals(updated_string, create_from_string("ABXXXXXXXXXXCD")), 1);
}

CU_pSuite run_replace_suite()
{
    CU_pSuite suite = CU_add_suite("'replace' suite", NULL, NULL);

    if (suite == NULL) 
    {
        printf("Error in creating test suite 'repeat'\n");
        return NULL;
    }

    CU_add_test(
        suite, 
        "replace with NULL to replace should return NULL", 
        test_replace_with_null_string_to_replace_returns_null
    );

    CU_add_test(
        suite, 
        "replace with valid invalid to replace should return NULL", 
        test_replace_with_invalid_string_to_replace_returns_null
    );

    CU_add_test(
        suite, 
        "replace with valid empty to replace should return NULL", 
        test_replace_with_empty_string_to_replace_returns_null
    );

    CU_add_test(
        suite, 
        "replace with valid string to replace and NULL replace pattern should return NULL", 
        test_replace_with_valid_string_to_replace_and_null_replace_pattern_returns_null
    );

    CU_add_test(
        suite, 
        "replace with valid string to replace and invalid replace pattern should return NULL", 
        test_replace_with_valid_string_to_replace_and_invalid_replace_pattern_returns_null
    );

    CU_add_test(
        suite, 
        "replace with valid string to replace and valid replace pattern and empty replace string should return input string", 
        test_replace_with_valid_string_to_replace_and_empty_replace_pattern_returns_returns_input_string
    );    

    CU_add_test(
        suite, 
        "replace with valid string to replace and valid replace pattern and NULL replace string should return NULL", 
        test_replace_with_valid_string_to_replace_and_valid_replace_pattern_and_null_replace_returns_null
    );

    CU_add_test(
        suite, 
        "replace with valid string to replace and valid replace pattern and invalid replace string should return NULL", 
        test_replace_with_valid_string_to_replace_and_valid_replace_pattern_and_invalid_replace_returns_null
    );

    CU_add_test(
        suite, 
        "replace with valid string to replace and valid replace pattern and empty replace string should return new string", 
        test_replace_with_valid_string_to_replace_and_valid_replace_pattern_and_empty_replace_returns_new_string
    );

    CU_add_test(
        suite, 
        "replace with valid string to replace and unknown replace pattern should return new string", 
        test_replace_with_valid_string_to_replace_and_unknown_replace_pattern_returns_new_string
    );

    CU_add_test(
        suite, 
        "replace with valid string to replace and valid replace pattern should return new string", 
        test_replace_with_valid_string_to_replace_and_valid_replace_pattern_returns_new_string
    );

    CU_add_test(
        suite, 
        "replace with valid string to replace and valid replace pattern should return new shorter string", 
        test_replace_with_valid_string_to_replace_and_valid_replace_pattern_returns_new_shorter_string
    );

    CU_add_test(
        suite, 
        "replace with valid string to replace and valid replace pattern should return longer string", 
        test_replace_with_valid_string_to_replace_and_valid_replace_pattern_returns_new_longer_string
    );

    return suite;
}