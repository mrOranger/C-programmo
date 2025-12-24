#include <stdio.h>

#include "libs/string/string.h"

int main (const int argc, const char** argv)
{
    String* input_string = create_from_string("AB123CD");
    String* pattern = create_from_string("123");
    String* string_to_replace = create_from_string("X");

    String* updated_string = replace(input_string, pattern, string_to_replace);

    return 0;
}