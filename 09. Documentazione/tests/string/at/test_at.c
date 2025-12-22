#include <CUnit/CUnit.h>

#include "test_at.h"

#include "../../../libs/string/string.h"

void test_at_with_input_string_null_returns_null()
{
    String* input_string    = NULL;
    size_t  index           = 2;

    String* new_string = at(input_string, index);

    CU_ASSERT_PTR_NULL(new_string);
    CU_ASSERT_EQUAL(size(new_string), 0);
}

void test_at_with_input_string_not_valid_returns_null()
{
    String* input_string    = create_from_string("ABCD");
    size_t  index           = 2;
    destroy(input_string);

    String* new_string = at(input_string, index);

    CU_ASSERT_PTR_NULL(new_string);
    CU_ASSERT_EQUAL(size(new_string), 0);
}

void test_at_with_invalid_index_returns_null()
{
    String* input_string    = create_from_string("ABCD");
    size_t  index           = 10;

    String* new_string = at(input_string, index);

    CU_ASSERT_PTR_NULL(new_string);
    CU_ASSERT_EQUAL(size(new_string), 0);
}

void test_at_returns_string()
{
    String* input_string    = create_from_string("ABCD");
    size_t  index           = 2;

    String* new_string = at(input_string, index);

    CU_ASSERT_PTR_NOT_NULL(new_string);
    CU_ASSERT_EQUAL(size(new_string), 1);
}

CU_pSuite run_at_string_suite()
{
    CU_pSuite suite = CU_add_suite("'at' suite", NULL, NULL);

    if (suite == NULL) 
    {
        printf("Error in creating test suite 'at'\n");
        return NULL;
    }

    CU_add_test(
        suite, 
        "at with input string null should return null", 
        test_at_with_input_string_null_returns_null
    );

    CU_add_test(
        suite, 
        "at with input string not valid should return null", 
        test_at_with_input_string_not_valid_returns_null
    );

    CU_add_test(
        suite, 
        "at with invalid index should return null", 
        test_at_with_invalid_index_returns_null
    );

    CU_add_test(
        suite, 
        "at should return new string", 
        test_at_returns_string
    );

    return suite;
}