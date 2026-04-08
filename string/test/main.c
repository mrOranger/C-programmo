#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "utils.c"

int main (const int argc, const char **argv)
{
    CU_ErrorCode registry_code = CU_initialize_registry();

    if (registry_code == CUE_NOMEMORY)
    {
        printf("Error in Test Registry Initialization!\n");

        return EXIT_FAILURE;
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);

    run_utils_testing_suite();

    CU_basic_run_tests();

    CU_cleanup_registry();

    return EXIT_SUCCESS;
}
