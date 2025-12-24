#include <CUnit/CUnit.h>

#include "test_equals.h"

#include "../../../libs/string/string.h"

void test_equals_with_first_string_null_returns_false()
{
    String* first_string    = create_empty();
    String* second_string   = NULL;

    u_int8_t is_equal = equals(first_string, second_string);

    CU_ASSERT_EQUAL(is_equal, 0);
}

void test_equals_with_second_string_null_returns_false()
{
    String* first_string    = NULL;
    String* second_string   = create_empty();

    u_int8_t is_equal = equals(first_string, second_string);

    CU_ASSERT_EQUAL(is_equal, 0);
}

void test_equals_with_first_and_second_string_null_returns_false()
{
    String* first_string    = NULL;
    String* second_string   = NULL;

    u_int8_t is_equal = equals(first_string, second_string);

    CU_ASSERT_EQUAL(is_equal, 0);
}

void test_equals_with_invalid_first_string_returns_false()
{
    String* first_string    = create_from_string("12345");
    String* second_string   = create_from_string("12345");
    destroy(first_string);

    u_int8_t is_equal = equals(first_string, second_string);

    CU_ASSERT_EQUAL(is_equal, 0);
}

void test_equals_with_invalid_second_string_returns_false()
{
    String* first_string    = create_from_string("12345");
    String* second_string   = create_from_string("12345");
    destroy(second_string);
    
    u_int8_t is_equal = equals(first_string, second_string);

    CU_ASSERT_EQUAL(is_equal, 0);
}

void test_equals_with_first_and_second_string_invalid_returns_false()
{
    String* first_string    = create_from_string("12345");
    String* second_string   = create_from_string("12345");
    destroy(first_string);
    destroy(second_string);
    
    u_int8_t is_equal = equals(first_string, second_string);

    CU_ASSERT_EQUAL(is_equal, 0);
}

void test_equals_with_different_sizes_string_returns_false()
{
    String* first_string    = create_from_string("1234");
    String* second_string   = create_from_string("12345");
    
    u_int8_t is_equal = equals(first_string, second_string);

    CU_ASSERT_EQUAL(is_equal, 0);
}

void test_equals_returns_false()
{
    String* first_string    = create_from_string("123456");
    String* second_string   = create_from_string("12345");
    
    u_int8_t is_equal = equals(first_string, second_string);

    CU_ASSERT_EQUAL(is_equal, 0);
}

void test_equals_returns_true()
{
    String* first_string    = create_from_string("12345");
    String* second_string   = create_from_string("12345");
    
    u_int8_t is_equal = equals(first_string, second_string);

    CU_ASSERT_EQUAL(is_equal, 1);
}

CU_pSuite run_equals_suite()
{
    CU_pSuite suite = CU_add_suite("'equals' suite", NULL, NULL);

    if (suite == NULL)
    {
        printf("Error in creating test suite 'equals'\n");
        return NULL;
    }

    CU_add_test(
        suite,
        "'equals' with first string null should return false", 
        test_equals_with_first_string_null_returns_false
    );

    CU_add_test(
        suite,
        "'equals' with second string null should return false", 
        test_equals_with_second_string_null_returns_false
    );

    CU_add_test(
        suite,
        "'equals' with first and second string null should return false", 
        test_equals_with_first_and_second_string_null_returns_false
    );

    CU_add_test(
        suite,
        "'equals' with invalid first string should return false", 
        test_equals_with_invalid_first_string_returns_false
    );

    CU_add_test(
        suite,
        "'equals' with invalid second string should return false", 
        test_equals_with_invalid_second_string_returns_false
    );

    CU_add_test(
        suite,
        "'equals' with invalid first and second string should returns false",
        test_equals_with_first_and_second_string_invalid_returns_false
    );

    CU_add_test(
        suite,
        "'equals' with invalid search string should returns false", 
        test_equals_with_invalid_second_string_returns_false
    );

    CU_add_test(
        suite,
        "'equals' with different sizes string should returns false", 
        test_equals_with_different_sizes_string_returns_false
    );

    CU_add_test(
        suite,
        "'equals' should return false",
        test_equals_returns_false
    );

    CU_add_test(
        suite,
        "'equals' should return true",
        test_equals_returns_true
    );

    return suite;
}

