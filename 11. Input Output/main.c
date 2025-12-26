#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

int min (const int args_number, ...);

int main (const int argc, const char** argv)
{
    char* pointer_to_string = (char*)calloc(20, sizeof(char));
    sprintf(pointer_to_string, "Ciao Mondo dal Linguaggio %c!\n", 'C');
    printf("%s", pointer_to_string);

    printf("Numero minimo di argomenti: %d\n", min(3, 1, -1, 3));

    return 0;
}

int min (const int args_number, ...)
{
    va_list args;
    int minimum = INT_MAX;
    va_start(args, args_number);

    for (int index = 0; index < args_number; index = index + 1)
    {
        int current_min = va_arg(args, int);

        if (current_min < minimum)
        {
            minimum = current_min;
        }
    }

    va_end(args);

    return minimum;
}

