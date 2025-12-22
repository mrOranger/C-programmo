#include <stdio.h>
#include <stdint.h>

#define MAX_LENGTH 100

#define swap(first, second, temp) { temp = first; first = second; second = temp; }

void print_cycle (const int length_to_print)
{
    if (length_to_print < MAX_LENGTH)
    {
        for (uint8_t index = 0; index <  length_to_print; index = index + 1)
        {
            printf(" index = %d / %d \n", index, MAX_LENGTH);
        }
    }
}

void swap_variables(int first, int second)
{
    int temp;

    swap(first, second, temp);

    printf("Swapped variables: first = %d, second = %d\n", first, second);
}


int main (const int argc, const char** argv)
{
    int first = 10, second = 20;

    print_cycle(10);
    swap_variables(first, second);

    return 0;
}
