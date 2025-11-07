#include <stdio.h>

int main (const int argc, const char** argv)
{
    int *int_ptr;
    int number = 0;

    int_ptr = &number;

    printf("int_ptr = %p, &number = %p\n", int_ptr, &number);
    printf("*int_ptr = %d, number = %d\n", *int_ptr, number);

    *int_ptr = (*int_ptr) + 1;

    printf("*int_ptr = %d, number = %d\n", *int_ptr, number);

    number = 10;
    int_ptr = &number;

    printf("int_ptr = %p, int_ptr + 1 = %p\n", int_ptr, int_ptr + 1);

    unsigned char a_char_vector[4];
    unsigned short int a_integer_vector[] = { 1, 2, 3, 4 };
    float a_float_vector[] = { 1, 2, 3, '\0' };

    return 0;
}
