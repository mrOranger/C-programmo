#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <stdint.h>

int min (const int args_number, ...);
uint8_t write_file (const char* path, const char* string);

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

    uint32_t random_integer;

    fprintf(stdout, "Sto scrivendo sullo standard output, mediante la funzione 'fprintf': ");
    fscanf(stdin, "%u", &random_integer);
    fprintf(stdout, "Sto scrivendo sullo standard output, mediante la funzione 'fprintf', il valore %u.\n", random_integer);

    printf("Sto scrivendo sullo standard output, mediante la funzione 'printf': ");
    scanf("%u", &random_integer);
    printf("Sto scrivendo sullo standard output, mediante la funzione 'printf', il valore %u.\n", random_integer);

    write_file("/Users/edooranger/Lavoro/C-programmo/file.dat", "Hello World from File!");

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

uint8_t write_file (const char* path, const char* string)
{
    FILE* file_pointer = fopen(path, "a");
    uint8_t written_chars = 0;

    if (file_pointer == NULL)
    {
        fprintf(stderr, "Cannot open file %s\n", path);
        return written_chars;
    }

    for (uint8_t index = 0; string[index] != '\0'; index++) 
    {
        int current_written_chars = putc(string[index], file_pointer);

        if (current_written_chars > 0) 
        {
            written_chars = written_chars + 1;
        }
    }

    return written_chars;
}

