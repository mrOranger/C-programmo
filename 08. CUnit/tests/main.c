#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "string/create_empty/test_create_empty.h"
#include "string/create_from_string/test_create_from_string.h"
#include "string/size/test_size.h"
#include "string/value/test_value.h"
#include "string/valid/test_valid.h"
#include "string/equals/test_equals.h"
#include "string/includes/test_includes.h"
#include "string/ends_with/test_ends_with.h"
#include "string/starts_with/test_starts_with.h"
#include "string/at/test_at.h"
#include "string/upper/test_upper.h"
#include "string/lower/test_lower.h"
#include "string/concat/test_concat.h"
#include "string/repeat/test_repeat.h"
#include "string/index_of/test_index_of.h"
#include "string/destroy/test_destroy.h"

int main (const int argc, const char** argv)
{
    CU_ErrorCode registry_code = CU_initialize_registry();
    
    if (registry_code == CUE_NOMEMORY) 
    {
        printf("Error in Test Registry initialization!\n");
        return EXIT_FAILURE;
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);

    run_create_empty_suite();
    run_create_from_string_suite();
    run_size_suite();
    run_value_suite();
    run_valid_suite();
    run_equals_suite();
    run_includes_suite();
    run_ends_with_suite();
    run_start_with_suite();
    run_at_string_suite();
    run_upper_string_suite();
    run_lower_string_suite();
    run_concat_suite();
    run_repeat_suite();
    run_index_of_suite();
    run_destroy_suite();

    CU_basic_run_tests();

    CU_cleanup_registry();

    return EXIT_SUCCESS;
}
