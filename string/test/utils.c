#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <stdlib.h>

#include "../src/utils/utils.h"

void test_clone_with_null_source_should_returns_null()
{
    char *string_to_clone = NULL;
    size_t bytes_to_clone = 0;

    char *cloned_string = clone(string_to_clone, bytes_to_clone);

    CU_ASSERT_PTR_NULL(cloned_string);
}

void test_clone_with_zero_number_of_bytes_should_returns_null()
{
    char *input_string = "This is a random string";
    size_t bytes_to_clone = 0;

    char *cloned_string = clone(input_string, bytes_to_clone);

    CU_ASSERT_PTR_NULL(cloned_string);
}

void test_clone_with_more_than_255_number_of_bytes_should_returns_null()
{
    char *input_string = "This is a random string";
    size_t bytes_to_clone = -1;

    char *cloned_string = clone(input_string, bytes_to_clone);

    CU_ASSERT_PTR_NULL(cloned_string);
}

void test_clone_should_returns_new_pointer()
{
    char *input_string = "This is a random string";
    size_t bytes_to_clone = 23;

    char *cloned_string = clone(input_string, bytes_to_clone);

    CU_ASSERT_PTR_NOT_NULL(cloned_string);
}

void test_copy_with_null_source_should_returns_null()
{
    char *source = NULL;
    char *destination = "This is a random string";
    size_t bytes_to_copy = 20;

    char *result = copy(source, destination, bytes_to_copy);

    CU_ASSERT_PTR_NULL(result);
}

void test_copy_with_null_destination_should_returns_null()
{
    char *source = "This is a random string";
    char *destination = NULL;
    size_t bytes_to_copy = 20;

    char *result = copy(source, destination, bytes_to_copy);

    CU_ASSERT_PTR_NULL(result);
}

void test_copy_with_more_than_of_255_bytes_should_returns_null()
{
    char *source = "This is a random string";
    char *destination = "This is a random string";
    size_t bytes_to_copy = -1;

    char *result = copy(source, destination, bytes_to_copy);

    CU_ASSERT_PTR_NULL(result);
}

void test_copy_with_zero_number_of_bytes_should_returns_null()
{
    char *source = "This is a random string";
    char *destination = "This is a random string";
    size_t bytes_to_copy = 0;

    char *result = copy(source, destination, bytes_to_copy);

    CU_ASSERT_PTR_NULL(result);
}

void test_copy_should_returns_new_pointer()
{
    char *source = "This is a random string";
    char *destination = "This will be another string";
    size_t bytes_to_copy = 20;

    char *result = copy(source, destination, bytes_to_copy);

    CU_ASSERT_PTR_NOT_NULL(result);
    CU_ASSERT_PTR_NOT_EQUAL(source, result);
    CU_ASSERT_PTR_EQUAL(destination, result);
}

void test_length_with_input_null_should_return_zero()
{

}

void test_length_with_valid_point_should_return_valid_length()
{
    
}

void run_utils_testing_suite()
{
    CU_pSuite suite = CU_add_suite("'utils' suite", NULL, NULL);

    if (suite == NULL)
    {
        printf("Error in creating test suite 'utils'\n");

        exit(EXIT_FAILURE);
    }

    CU_add_test(
        suite, 
        "'clone' with NULL source, should returns NULL", 
        test_clone_with_null_source_should_returns_null
    );

    CU_add_test(
        suite, 
        "'clone' with zero number of bytes, should returns NULL", 
        test_clone_with_zero_number_of_bytes_should_returns_null
    );

    CU_add_test(
        suite, 
        "'clone' with most than 255 number of bytes, should returns NULL", 
        test_clone_with_more_than_255_number_of_bytes_should_returns_null
    );

    CU_add_test(
        suite, 
        "'clone' should returns new pointer", 
        test_clone_should_returns_new_pointer
    );

    CU_add_test(
        suite, 
        "'copy' with NULL source should returns NULL", 
        test_copy_with_null_source_should_returns_null
    );

    CU_add_test(
        suite, 
        "'copy' with NULL destination should returns NULL", 
        test_copy_with_null_destination_should_returns_null
    );

    CU_add_test(
        suite, 
        "'copy' with more than 255 bytes should returns NULL", 
        test_copy_with_more_than_of_255_bytes_should_returns_null
    );

    CU_add_test(
        suite, 
        "'copy' with zero number of bytes should returns new pointer", 
        test_copy_with_zero_number_of_bytes_should_returns_null
    );

    CU_add_test(
        suite, 
        "'copy' should returns new pointer", 
        test_copy_should_returns_new_pointer
    );

    CU_add_test(
        suite, 
        "'length' with NULL pointer, should return zero", 
        test_length_with_input_null_should_return_zero
    );

    CU_add_test(
        suite, 
        "'length' should return right length", 
        test_length_with_valid_point_should_return_valid_length
    );    
}
