#include <CUnit/CUnit.h>

#include "test_index_of.h"

#include "../../../libs/string/string.h"

void test_index_of_with_input_string_null_returns_false()
{
    String* input_string    = create_from_string("abcd");
    String* search_string   = NULL;

    int32_t index = index_of(input_string, search_string);

    CU_ASSERT_EQUAL(index, -1);
}

void test_index_of_with_search_string_null_returns_false()
{
    String* input_string    = NULL;
    String* search_string   = create_from_string("abcd");

    int32_t index = index_of(input_string, search_string);

    CU_ASSERT_EQUAL(index, -1);
}

void test_index_of_with_input_and_search_string_null_returns_false()
{
    String* input_string    = NULL;
    String* search_string   = NULL;

    int32_t index = index_of(input_string, search_string);

    CU_ASSERT_EQUAL(index, -1);
}

void test_index_of_with_input_string_invalid_returns_false()
{
    String* input_string    = create_from_string("abcd");
    String* search_string   = create_from_string("bc");
    destroy(input_string);

    int32_t index = index_of(input_string, search_string);

    CU_ASSERT_EQUAL(index, -1);
}

void test_index_of_with_search_string_invalid_returns_false()
{
    String* input_string    = create_from_string("abcd");
    String* search_string   = create_from_string("bc");
    destroy(search_string);

    int32_t index = index_of(input_string, search_string);

    CU_ASSERT_EQUAL(index, -1);
}

void test_index_of_with_input_and_search_string_invalid_returns_false()
{
    String* input_string    = create_from_string("abcd");
    String* search_string   = create_from_string("bc");
    destroy(input_string);
    destroy(search_string);

    int32_t index = index_of(input_string, search_string);

    CU_ASSERT_EQUAL(index, -1);
}

void test_index_of_with_input_string_smaller_then_search_string_returns_false()
{
    String* input_string    = create_from_string("abcd");
    String* search_string   = create_from_string("bcdef");

    int32_t index = index_of(input_string, search_string);

    CU_ASSERT_EQUAL(index, -1);
}

void test_index_of_returns_negative_number()
{
    String* input_string    = create_from_string("abcd");
    String* search_string   = create_from_string("efg");

    int32_t index = index_of(input_string, search_string);

    CU_ASSERT_EQUAL(index, -1);
}

void test_index_of_returns_right_index()
{
    String* input_string    = create_from_string("abcd");
    String* search_string   = create_from_string("bc");

    int32_t index = index_of(input_string, search_string);

    CU_ASSERT_EQUAL(index, 1);
}

CU_pSuite run_index_of_suite()
{
    CU_pSuite suite = CU_add_suite("'index_of' suite", NULL, NULL);

    if (suite == NULL)
    {
        printf("Error in creating test suite 'index_of'\n");
        return NULL;
    }

    CU_add_test(
        suite,
        "'index_of' with input string null should return false", 
        test_index_of_with_input_string_null_returns_false
    );

    CU_add_test(
        suite,
        "'index_of' with search string null should return false", 
        test_index_of_with_search_string_null_returns_false
    );

    CU_add_test(
        suite,
        "'index_of' with input and search string null should return false", 
        test_index_of_with_input_and_search_string_null_returns_false
    );

    CU_add_test(
        suite,
        "'index_of' with input string invalid should returns false", 
        test_index_of_with_input_string_invalid_returns_false
    );

    CU_add_test(
        suite,
        "'index_of' with search string invalid should return false", 
        test_index_of_with_search_string_invalid_returns_false
    );

    CU_add_test(
        suite,
        "'index_of' with input and search string invalid should return false",
        test_index_of_with_input_and_search_string_invalid_returns_false
    );

    CU_add_test(
        suite,
        "'index_of' with input string smaller then search string should return false", 
        test_index_of_with_input_string_smaller_then_search_string_returns_false
    );

    CU_add_test(
        suite,
        "'index_of' should return false",
        test_index_of_returns_negative_number
    );

    CU_add_test(
        suite,
        "'index_of' should return true",
        test_index_of_returns_right_index
    );

    return suite;
}