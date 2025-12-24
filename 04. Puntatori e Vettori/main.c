#include <stdio.h>
#include <stdint.h>

#define MAX_COLS 1000
#define MAX_ROWS 1000

char* write (char* matrix, uint8_t row_index, uint8_t col_index, char value)
{
    if (row_index >= ((uint8_t) MAX_ROWS)) {
        printf("Invalid row index");
        return NULL;
    }

    if (col_index >= ((uint8_t) MAX_COLS)) {
        printf("Invalid column index");
        return NULL;
    }

    int offset = row_index * MAX_COLS + col_index + sizeof(char);

    *(matrix + offset) = value;

    return matrix + offset;
}

char* read (char* matrix, uint8_t row_index, uint8_t col_index)
{
    if (row_index >= ((uint8_t) MAX_ROWS)) {
        printf("Invalid row index");
        return NULL;
    }

    if (col_index >= ((uint8_t) MAX_COLS)) {
        printf("Invalid column index");
        return NULL;
    }

    int offset = row_index * MAX_COLS + col_index + sizeof(char);

    return matrix + offset;
}

char* erease (char* matrix, uint8_t row_index, uint8_t col_index)
{
    if (row_index >= ((uint8_t) MAX_ROWS)) {
        printf("Invalid row index");
        return NULL;
    }

    if (col_index >= ((uint8_t) MAX_COLS)) {
        printf("Invalid column index");
        return NULL;
    }

    int offset = row_index * MAX_COLS + col_index + sizeof(char);

    *(matrix + offset) = '\0';

    return matrix + offset;
}

void print(char* matrix)
{
    for (uint8_t row = 0; row < (uint8_t) MAX_ROWS; row++) {
        for (uint8_t col = 0; col < (uint8_t) MAX_COLS; col++) {
            char* index = read(matrix, row, col);
            if (*index != '\0') {
                printf("matrix[%u][%u] = %c\n", row, col, *index);
            }
        }
    }
}

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

    char matrix[MAX_COLS * MAX_ROWS];

    write(matrix, 0, 0, 'A');
    write(matrix, 0, 1, 'B');
    write(matrix, 0, 2, 'C');
    write(matrix, 1, 0, 'D');
    write(matrix, 1, 1, 'E');

    print(matrix);

    return 0;
}
