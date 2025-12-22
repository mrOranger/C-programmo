#include <CUnit/CUnit.h>

#include "test_starts_with.h"

#include "../../../libs/string/string.h"

void test_starts_with_with_input_string_null_returns_false()
{
    String* input_string    = create_empty();
    String* search_string   = NULL;

    uint8_t does_starts_with = starts_with(input_string, search_string);

    CU_ASSERT_EQUAL(does_starts_with, 0);
}

void test_starts_with_with_search_string_null_returns_false()
{
    String* input_string    = NULL;
    String* search_string   = create_empty();

    uint8_t does_starts_with = starts_with(input_string, search_string);

    CU_ASSERT_EQUAL(does_starts_with, 0);
}

void test_starts_with_with_input_string_and_search_string_null_returns_false()
{
    String* input_string    = NULL;
    String* search_string   = NULL;

    uint8_t does_starts_with = starts_with(input_string, search_string);

    CU_ASSERT_EQUAL(does_starts_with, 0);
}

void test_starts_with_with_input_string_invalid_returns_false()
{
    String* input_string    = create_from_string("123456789");
    String* search_string   = create_from_string("789");
    destroy(input_string);

    uint8_t does_starts_with = starts_with(input_string, search_string);

    CU_ASSERT_EQUAL(does_starts_with, 0);
}

void test_starts_with_with_search_string_invalid_returns_false()
{
    String* input_string    = create_from_string("123456789");
    String* search_string   = create_from_string("789");
    destroy(search_string);

    uint8_t does_starts_with = starts_with(input_string, search_string);

    CU_ASSERT_EQUAL(does_starts_with, 0);
}

void test_starts_with_with_input_string_and_search_string_invalid_returns_false()
{
    String* input_string    = create_from_string("123456789");
    String* search_string   = create_from_string("789");
    destroy(input_string);
    destroy(search_string);

    uint8_t does_starts_with = starts_with(input_string, search_string);

    CU_ASSERT_EQUAL(does_starts_with, 0);
}

void test_starts_with_with_input_string_smaller_than_search_string_returns_false()
{
    String* input_string    = create_from_string("12");
    String* search_string   = create_from_string("123");

    uint8_t does_starts_with = starts_with(input_string, search_string);

    CU_ASSERT_EQUAL(does_starts_with, 0);
}

void test_starts_with_returns_false()
{
    String* input_string    = create_from_string("123456789");
    String* search_string   = create_from_string("345");

    uint8_t does_starts_with = starts_with(input_string, search_string);

    CU_ASSERT_EQUAL(does_starts_with, 0);
}

void test_starts_with_returns_true()
{
    String* input_string    = create_from_string("123456789");
    String* search_string   = create_from_string("123");

    uint8_t does_starts_with = starts_with(input_string, search_string);

    CU_ASSERT_EQUAL(does_starts_with, 1);
}

CU_pSuite run_start_with_suite()
{
    CU_pSuite suite = CU_add_suite("'starts_with' suite", NULL, NULL);

    if (suite == NULL)
    {
        printf("Error in creating test suite 'starts_with'\n");
        return NULL;
    }

    CU_add_test(
        suite,
        "'starts_with' with first string null should return false", 
        test_starts_with_with_input_string_null_returns_false
    );

    CU_add_test(
        suite,
        "'starts_with' with second string null should return false", 
        test_starts_with_with_search_string_null_returns_false
    );

    CU_add_test(
        suite,
        "'starts_with' with first and second string null should return false", 
        test_starts_with_with_input_string_and_search_string_null_returns_false
    );

    CU_add_test(
        suite,
        "'starts_with' with invalid first string should return false", 
        test_starts_with_with_input_string_invalid_returns_false
    );

    CU_add_test(
        suite,
        "'starts_with' with invalid second string should return false", 
        test_starts_with_with_search_string_invalid_returns_false
    );

    CU_add_test(
        suite,
        "'starts_with' with invalid first and second string should returns false",
        test_starts_with_with_input_string_and_search_string_invalid_returns_false
    );

    CU_add_test(
        suite,
        "'starts_with' input string smaller than search string should return false", 
        test_starts_with_with_input_string_smaller_than_search_string_returns_false
    );

    CU_add_test(
        suite,
        "'starts_with' should return false",
        test_starts_with_returns_false
    );

    CU_add_test(
        suite,
        "'starts_with' should return true",
        test_starts_with_returns_true
    );

    return suite;
}