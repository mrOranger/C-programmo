#include <CUnit/CUnit.h>

#include "test_create_from_string.h"

#include "../../../libs/string/string.h"

void test_create_from_string_with_null_returns_null()
{
    char* input_string = NULL;

    String* new_string = create_from_string(input_string);

    CU_ASSERT_PTR_NULL(new_string);
}

void test_create_from_string_with_empty_string_returns_empty_string()
{
    char* input_string = "";

    String* new_string = create_from_string(input_string);

    CU_ASSERT_EQUAL(size(new_string), 0);
    CU_ASSERT_EQUAL(valid(new_string), 1);
    CU_ASSERT_PTR_NOT_NULL(value(new_string));
}

void test_create_from_longer_string_returns_null()
{
    char* input_string = "Proin lobortis semper porttitor. Pellentesque lacinia, diam vel consequat faucibus, risus augue egestas ipsum, sit amet facilisis mauris purus at nisi. Etiam semper nunc a elit semper varius. Vestibulum nec justo tristique, tempor lacus sit amet porttitor.";

    String* new_string = create_from_string(input_string);

    CU_ASSERT_PTR_NULL(new_string);
}

void test_create_from_string_returns_new_string()
{
    char* input_string = "Proin lobortis";

    String* new_string = create_from_string(input_string);

    CU_ASSERT_EQUAL(size(new_string), 14);
    CU_ASSERT_EQUAL(valid(new_string), 1);
    CU_ASSERT_PTR_NOT_NULL(value(new_string));
}

CU_pSuite run_create_from_string_suite()
{
    CU_pSuite suite = CU_add_suite("'create_from_string' suite", NULL, NULL);

    if (suite == NULL)
    {
        printf("Error in creating test suite 'create_from_string'\n");
        return NULL;
    }

    CU_add_test(
        suite, 
        "'create_from_string' with NULL input should return NULL", 
        test_create_from_string_with_null_returns_null
    );

    CU_add_test(
        suite, 
        "'create_from_string' with empty input should return empty string", 
        test_create_from_string_with_empty_string_returns_empty_string
    );

    CU_add_test(
        suite, 
        "'create_from_string' with long input string should return NULL", 
        test_create_from_longer_string_returns_null
    );

    CU_add_test(
        suite, 
        "'create_from_string' with regular string should return new string", 
        test_create_from_string_returns_new_string
    );

    return suite;
}
