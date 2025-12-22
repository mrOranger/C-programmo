#include <CUnit/CUnit.h>

#include "test_create_empty.h"

#include "../../../libs/string/string.h"

void test_create_empty() 
{
    String* new_string = create_empty();

    CU_ASSERT_PTR_NOT_NULL(new_string);
}

CU_pSuite run_create_empty_suite()
{
    CU_pSuite suite = CU_add_suite("'create_empty' suite", NULL, NULL);

    if (suite == NULL) 
    {
        printf("Error in creating test suite 'create_empty'\n");
        return NULL;
    }

    CU_add_test(
        suite, 
        "create_empty should returns a pointer to String", 
        test_create_empty
    );

    return suite;
}
