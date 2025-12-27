#include <stdlib.h>
#include <CUnit/CUnit.h>

#include "../../libs/client/client.h"

void test_new_client_with_tax_code_null_should_return_null()
{
    const char* tax_code = NULL;
    const char* first_name = "John";
    const char* last_name = "Doe";

    client_t* client = new_client(tax_code, first_name, last_name);

    CU_ASSERT_EQUAL(client, NULL);
}

void test_new_client_with_first_name_null_should_return_null()
{
    const char* tax_code = "ABCDEF00A00A000A";
    const char* first_name = NULL;
    const char* last_name = "Doe";

    client_t* client = new_client(tax_code, first_name, last_name);

    CU_ASSERT_EQUAL(client, NULL);
}

void test_new_client_with_last_name_null_should_return_null()
{
    const char* tax_code = "ABCDEF00A00A000A";
    const char* first_name = "John";
    const char* last_name = NULL;

    client_t* client = new_client(tax_code, first_name, last_name);

    CU_ASSERT_EQUAL(client, NULL);
}

void test_new_client_with_tax_code_longer_than_sixteen_chars_should_return_null()
{
    const char* tax_code = "ABCDEF00A00A000AA";
    const char* first_name = "John";
    const char* last_name = "Doe";

    client_t* client = new_client(tax_code, first_name, last_name);

    CU_ASSERT_EQUAL(client, NULL);
}

void test_new_client_with_tax_code_shorter_than_sixteen_chars_should_return_null()
{
    const char* tax_code = "ABCDEF00A00A00";
    const char* first_name = "John";
    const char* last_name = "Doe";

    client_t* client = new_client(tax_code, first_name, last_name);

    CU_ASSERT_EQUAL(client, NULL);
}

void test_new_client_should_return_not_null_pointer()
{
    const char* tax_code = "ABCDEF00A00A000A";
    const char* first_name = "John";
    const char* last_name = "Doe";

    client_t* client = new_client(tax_code, first_name, last_name);

    CU_ASSERT_NOT_EQUAL(client, NULL);
}

CU_pSuite run_test_new_cliet_suite()
{
    CU_pSuite suite = CU_add_suite("'new_client' suite", NULL, NULL);

    if (suite == NULL) 
    {
        printf("Error in creating test suite 'new_client'\n");
        exit(-1);

        return NULL;
    }

    CU_add_test(
        suite,
        "new_client with tax_code NULL should return null",
        test_new_client_with_tax_code_null_should_return_null
    );

    CU_add_test(
        suite,
        "new_client with first_name NULL should return null",
        test_new_client_with_first_name_null_should_return_null
    );

    CU_add_test(
        suite,
        "new_client with last_name NULL should return null",
        test_new_client_with_last_name_null_should_return_null
    );

    CU_add_test(
        suite,
        "new_client with tax_code longer than sixteen chars should return null",
        test_new_client_with_tax_code_longer_than_sixteen_chars_should_return_null
    );

    CU_add_test(
        suite,
        "new_client with tax_code shorter than sixteen chars should return null",
        test_new_client_with_tax_code_shorter_than_sixteen_chars_should_return_null
    );

    CU_add_test(
        suite, 
        "new_client should return not null pointer", 
        test_new_client_should_return_not_null_pointer
    );

    return suite;
}
