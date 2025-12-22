#include <CUnit/CUnit.h>

#include "test_destroy.h"

#include "../../../libs/string/string.h"

void test_destroy_with_string_null_returns_null()
{
    String* input_string = NULL;

    destroy(input_string);

    CU_ASSERT_EQUAL(valid(input_string), 0);
}

void test_destroy_with_string_invalid_returns_null()
{
    String* input_string = create_from_string("abcd");
    destroy(input_string);

    destroy(input_string);

    CU_ASSERT_EQUAL(valid(input_string), 0);
}

void test_destroy_success()
{
    String* input_string = create_from_string("abcd");

    destroy(input_string);

    CU_ASSERT_EQUAL(valid(input_string), 0);
}

CU_pSuite run_destroy_suite()
{
    CU_pSuite suite = CU_add_suite("'destroy' suite", NULL, NULL);

    if (suite == NULL)
    {
        printf("Error in creating test suite 'destroy'\n");
        return NULL;
    }

    CU_add_test(
        suite, 
        "'destroy' with NULL input should return NULL", 
        test_destroy_with_string_null_returns_null
    );

    CU_add_test(
        suite, 
        "'destroy' with invalid input should return NULL", 
        test_destroy_with_string_invalid_returns_null
    );

    CU_add_test(
        suite, 
        "'destroy' should return destroyed string", 
        test_destroy_success
    );

    return suite;
}