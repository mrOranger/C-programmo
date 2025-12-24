#include <stdio.h>

unsigned long int iterative_factorial (unsigned short int number)
{
    unsigned long int starting_number = 1;

    for (unsigned short int index = 1; index <= number; index++)
    {
        starting_number = starting_number * index;
    }

    return starting_number;
}

unsigned long int recursive_factorial (unsigned short int number)
{
    if (number == 0)
    {
        return 1;
    }

    return number * recursive_factorial(number - 1);
}

int main (const int argc, const char** arvg)
{
    unsigned long int iterative_factorial_result = iterative_factorial(10);
    unsigned long int recursive_factorial_result = recursive_factorial(10);

    printf("\t1.(Iterative)\t10! = %lu\n", iterative_factorial_result);
    printf("\t2.(Recursive)\t10! = %lu\n", recursive_factorial_result);

    return 0;
}
