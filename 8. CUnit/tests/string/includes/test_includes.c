#include <CUnit/CUnit.h>

#include "test_includes.h"

#include "../../../libs/string/string.h"

void test_includes_with_input_string_null_returns_false()
{
    String* input_string    = create_empty();
    String* search_string   = NULL;

    uint8_t is_included = includes(input_string, search_string);

    CU_ASSERT_EQUAL(is_included, 0);
}

void test_includes_with_search_string_null_returns_false()
{
    String* input_string    = NULL;
    String* search_string   = create_empty();

    uint8_t is_included = includes(input_string, search_string);

    CU_ASSERT_EQUAL(is_included, 0);
}

void test_includes_with_input_and_search_string_null_returns_false()
{
    String* input_string    = NULL;
    String* search_string   = NULL;

    uint8_t is_included = includes(input_string, search_string);

    CU_ASSERT_EQUAL(is_included, 0);
}

void test_includes_with_input_string_invalid_returns_false()
{
    String* input_string    = create_from_string("123");
    String* search_string   = create_from_string("123");
    destroy(input_string);

    uint8_t is_included = includes(input_string, search_string);

    CU_ASSERT_EQUAL(is_included, 0);
}

void test_includes_with_search_string_invalid_returns_false()
{
    String* input_string    = create_from_string("123");
    String* search_string   = create_from_string("123");
    destroy(search_string);

    uint8_t is_included = includes(input_string, search_string);

    CU_ASSERT_EQUAL(is_included, 0);
}

void test_includes_with_input_and_search_string_invalid_returns_false()
{
    String* input_string    = create_from_string("123");
    String* search_string   = create_from_string("123");
    destroy(input_string);
    destroy(search_string);

    uint8_t is_included = includes(input_string, search_string);

    CU_ASSERT_EQUAL(is_included, 0);
}

void test_includes_with_input_string_smaller_then_search_string_returns_false()
{
    String* input_string    = create_from_string("12");
    String* search_string   = create_from_string("123");

    uint8_t is_included = includes(input_string, search_string);

    CU_ASSERT_EQUAL(is_included, 0);
}

void test_includes_returns_false()
{
    String* input_string    = create_from_string("123456");
    String* search_string   = create_from_string("789");

    uint8_t is_included = includes(input_string, search_string);

    CU_ASSERT_EQUAL(is_included, 0);
}

void test_includes_returns_true()
{
    String* input_string    = create_from_string("123456");
    String* search_string   = create_from_string("345");

    uint8_t is_included = includes(input_string, search_string);

    CU_ASSERT_EQUAL(is_included, 1);
}

CU_pSuite run_includes_suite()
{
    CU_pSuite suite = CU_add_suite("'includes' suite", NULL, NULL);

    if (suite == NULL)
    {
        printf("Error in creating test suite 'includes'\n");
        return NULL;
    }

    CU_add_test(
        suite,
        "'includes' with input string null should return false", 
        test_includes_with_input_string_null_returns_false
    );

    CU_add_test(
        suite,
        "'includes' with search string null should return false", 
        test_includes_with_search_string_null_returns_false
    );

    CU_add_test(
        suite,
        "'includes' with input and search string null should return false", 
        test_includes_with_input_and_search_string_null_returns_false
    );

    CU_add_test(
        suite,
        "'includes' with input string invalid should returns false", 
        test_includes_with_input_string_invalid_returns_false
    );

    CU_add_test(
        suite,
        "'includes' with search string invalid should return false", 
        test_includes_with_search_string_invalid_returns_false
    );

    CU_add_test(
        suite,
        "'includes' with input and search string invalid should return false",
        test_includes_with_input_and_search_string_invalid_returns_false
    );

    CU_add_test(
        suite,
        "'includes' with input string smaller then search string should return false", 
        test_includes_with_input_string_smaller_then_search_string_returns_false
    );

    CU_add_test(
        suite,
        "'includes' should return false",
        test_includes_returns_false
    );

    CU_add_test(
        suite,
        "'includes' should return true",
        test_includes_returns_true
    );

    return suite;
}