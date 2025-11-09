#include <stdio.h>
#include <stdint.h>

struct person_ {
    char* first_name;
    char* last_name;
    uint8_t age;
};

int main (const int argc, const char** argv)
{
    printf ("sizeof(struct person) = %lu byte\n", sizeof(struct person));
    printf ("sizeof(uint8_t) = %lu byte, sizeof(char*) = %lu byte\n", sizeof(uint8_t), sizeof(char*));

    return 0;
}
