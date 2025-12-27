#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "client/new_client.c"
#include "client/get_tax_code.c"

int main (const int argc, const char** argv)
{
    CU_ErrorCode registry_code = CU_initialize_registry();
    
    if (registry_code == CUE_NOMEMORY) 
    {
        printf("Error in Test Registry initialization!\n");

        return EXIT_FAILURE;
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);

    run_test_new_cliet_suite();
    run_test_get_tax_code_suite();

    CU_basic_run_tests();

    CU_cleanup_registry();

    return EXIT_SUCCESS;
}
