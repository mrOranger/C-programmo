#include <stdio.h>

#include "libs/string/string.h"

int main (const int argc, const char** argv)
{
    void* input_string = "ab123cd";
    size_t starting_index = 2;
    size_t n_bytes = 3;

    void* string_copy = string_ncopy(input_string, n_bytes, starting_index);

    printf("%s - %d\n", string_copy, string_length(string_copy));

    return 0;
}
