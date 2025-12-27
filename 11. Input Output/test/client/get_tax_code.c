#include <CUnit/CUnit.h>

#include "../../libs/client/client.h"

void test_get_tax_code_with_client_null_should_return_null()
{
    client_t* client = NULL;

    const char* tax_code = get_tax_code(client);
    
    CU_ASSERT_EQUAL(tax_code, NULL);
}

void test_get_tax_code_with_client_not_valid_should_return_null()
{
    client_t* client = new_client("AAAAAA00A00A000A", "John", "Doe");
    destroy_client(client);

    const char* tax_code = get_tax_code(client);
    
    CU_ASSERT_EQUAL(tax_code, NULL);
}

void test_get_tax_code_should_return_pointer_not_null()
{
    client_t* client = new_client("AAAAAA00A00A000A", "John", "Doe");

    const char* tax_code = get_tax_code(client);
    
    CU_ASSERT_NOT_EQUAL(tax_code, NULL);
}

CU_pSuite run_test_get_tax_code_suite()
{
    CU_pSuite suite = CU_add_suite("'get_tax_code' suite", NULL, NULL);

    if (suite == NULL) 
    {
        printf("Error in creating test suite 'get_tax_code'\n");
        exit(-1);

        return NULL;
    }

    CU_add_test(
        suite,
        "get_tax_code with client NULL should return NULL",
        test_get_tax_code_with_client_null_should_return_null
    );

    CU_add_test(
        suite,
        "get_tax_code with client not valid should return NULL",
        test_get_tax_code_with_client_not_valid_should_return_null
    );

    CU_add_test(
        suite,
        "get_tax_code should return pointer not NULL",
        test_get_tax_code_should_return_pointer_not_null
    );

    return suite;
}
