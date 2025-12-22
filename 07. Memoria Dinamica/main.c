#include <stdio.h>

#include "./libs/string/string.h"

int main (const int argc, const char** argv)
{
    String* first_name = create_string("Edoardo");
    String* last_name  = create_string("Oranger");
    String* full_name  = concat(first_name, last_name);

    printf("first_name = %s, last_name = %s, full_name = %s\n", value(first_name), value(last_name), value(full_name));
    printf("includes(first_name, last_name) = %u\n", includes(first_name, last_name));
    printf("includes(full_name, last_name) = %u\n", includes(full_name, last_name));
    printf("includes(full_name, first_name) = %u\n", includes(full_name, first_name));
    printf("upper(first_name) = %s, upper(last_name) = %s\n", value(upper(first_name)), value(upper(last_name)));
    printf("lower(first_name) = %s, lower(last_name) = %s\n", value(lower(first_name)), value(lower(last_name)));

    destroy(first_name);
    destroy(last_name);

    printf("first_name = %s, last_name = %s\n", value(first_name), value(last_name));

    return 0;
}
