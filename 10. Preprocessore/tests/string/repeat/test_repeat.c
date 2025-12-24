#include <stdint.h>
#include <CUnit/CUnit.h>

#include "test_repeat.h"

#include "../../../libs/string/string.h"

void test_repeat_with_input_string_null_returns_null()
{
    String* input_string = NULL;
    uint8_t repetitions  = 2;

    String* result = repeat(input_string, repetitions);

    CU_ASSERT_PTR_NULL(result);
}

void test_repeat_with_input_string_invalid_returns_null()
{
    String* input_string = create_from_string("abcd");
    uint8_t repetitions  = 2;
    destroy(input_string);

    String* result = repeat(input_string, repetitions);

    CU_ASSERT_PTR_NULL(result);
}

void test_repeat_with_input_repetitions_zero_returns_empty_string()
{
    String* input_string = create_from_string("abcd");
    uint8_t repetitions  = 0;

    String* result = repeat(input_string, repetitions);

    CU_ASSERT_PTR_NOT_NULL(result);
    CU_ASSERT_EQUAL(equals(result, create_empty()), 1);
}

void test_repeat_returns_new_string()
{
    String* input_string = create_from_string("abcd");
    uint8_t repetitions  = 2;

    String* result = repeat(input_string, repetitions);

    CU_ASSERT_PTR_NOT_NULL(result);
    CU_ASSERT_EQUAL(equals(result, create_from_string("abcdabcd")), 1);
}

CU_pSuite run_repeat_suite()
{
    CU_pSuite suite = CU_add_suite("'repeat' suite", NULL, NULL);

    if (suite == NULL) 
    {
        printf("Error in creating test suite 'repeat'\n");
        return NULL;
    }

    CU_add_test(
        suite, 
        "repeat with input string null should return null", 
        test_repeat_with_input_string_null_returns_null
    );

    CU_add_test(
        suite, 
        "repeat with input string invalid should return null", 
        test_repeat_with_input_string_invalid_returns_null
    );

    CU_add_test(
        suite, 
        "repeat with input input repetitions zero should return empty string", 
        test_repeat_with_input_repetitions_zero_returns_empty_string
    );

    CU_add_test(
        suite, 
        "repeat returns new string", 
        test_repeat_returns_new_string
    );

    return suite;
}