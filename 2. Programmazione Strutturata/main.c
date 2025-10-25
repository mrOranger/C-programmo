#include <stdio.h>

int main (int argc, const char** argv)
{
    {
        unsigned short int random_variable = 1;
        printf("Inside this block there is the variable %u\n", random_variable);
    }

    unsigned short int first_variable = 0;
    unsigned short int second_variable = 1;

    if (first_variable * second_variable == 0) {
        printf("I'm inside the block below the 'if' keyword\n");
    } else {
        printf("I'm below the block described by the 'else' keyword\n");
    }

    if (first_variable * second_variable == 1) {
        printf("I'm inside the block below the 'if' keyword\n");
    } else {
        if (first_variable == 0) {
            printf("I'm inside the block below the 'if' keyword, below the first 'else' keyword\n");
        } else {
            printf("I'm inside the block below the 'else' keyword, below the first 'else' keyword\n");
        }
    }

    unsigned char first_char = 1;
    unsigned char second_char = 2;

    if (first_char + second_char == 3)
        printf("first_char + second_char == 3\n");
        if (first_char == 2)
            printf("first_char == 2\n");
    else 
        printf("first_char + second_char != 3\n");

    unsigned short int counter = 0;

    condition: {
        if (counter < 10) { 
            goto body;
        } else {
            goto rest;
        }
    }

    body: {
        printf("i'm doing something using counter = %u\n", counter);
        counter++;
        goto condition;
    }

    rest: {
        printf("i'm out of the iteration\n");
    }

    unsigned short int while_counter = 0;

    while (while_counter < 10) {
        printf("(while) counter = %u\n", while_counter);
        while_counter++;
    }

    unsigned short int do_counter = 0;

    do {
        printf("(do-while) counter = %u\n", do_counter);
        do_counter++;
    }while(do_counter < 10);

    for (unsigned short int for_counter = 0; for_counter < 10; for_counter++) {
        printf("(for) counter = %u\n", for_counter);
    }

    for (unsigned short int counter = 0; counter < 10; counter++) {
        if (counter == 3) {
            printf ("I found the element %u!\n", counter);
            break;
        }
    }

    for (unsigned short int counter = 0; counter < 10; counter++) {
        if (counter % 2 == 0) {
            printf("The element %u is even!\n", counter);
        } else {
            continue;
        }
    }

    printf("Process Started ...\n");
    goto success;

    success: {
         printf("Process Completed!\n");
         return 0;
    }

    error: {
       printf("Process Failed!\n");
       return -1;
    }

    return 0;
}
