#include <stdio.h>
#include <stdint.h>

#define MAX_LENGTH 100

void print_cycle (const int length_to_print)
{
    if (length_to_print < MAX_LENGTH)
    {
        for (uint8_t index = 0; index <  length_to_print; index = index + 1)
        {
            printf(" index = %d / " #MAX_LENGTH "\n", index);
        }
    }
}

int main (const int argc, const char** argv)
{
    print_cycle(10);
    return 0;
}
