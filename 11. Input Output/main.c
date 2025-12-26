#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <stdint.h>

int min (const int args_number, ...);

int main (const int argc, const char** argv)
{
    char* pointer_to_string = (char*)calloc(20, sizeof(char));
    char* current_date = (char*)calloc(20, sizeof(char));
    uint32_t day, month, year;

    sprintf(pointer_to_string, "Ciao Mondo dal Linguaggio %c!\n", 'C');
    printf("%s", pointer_to_string);

    printf("Numero minimo di argomenti: %d\n", min(3, 1, -1, 3));

    // printf("Inserisci la data corrente in formato dd/mm/yyyy: ");
    // scanf("%u/%u/%u", &day, &month, &year);
    // printf("Il giorno corrente è: %u/%u/%u\n", day, month, year);
    
    current_date = "26/12/2025";
    sscanf(current_date, "%u/%u/%u", &day, &month, &year);
    printf("Il giorno corrente è: %u/%u/%u\n", day, month, year);

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
