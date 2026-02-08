#include <stddef.h>

#include "string.h"

struct _string {
    char *character_sequence;
    size_t length;
    uint8_t valid:1;
};

/**
 * Creates a new array cloning n_bytes from the source.
 * 
 * @param source pointer to the source data to copy.
 * @param n_bytes number of bytes to copy.
 * @return pointer to the array result by the copy operation.
 */
char *clone(char *source, size_t n_bytes)
{
    if (source == NULL)
    {
        return source;
    }
    
    char* cloned_source = (char*)calloc(n_bytes, sizeof(char));

    for (size_t index = 0; index < n_bytes || source[index] != '\0'; index++)
    {
        cloned_source[index] = source[index];
    }

    return cloned_source;
}

/**
 * Copy n_bytes from the source data to the destination data, returning the pointer to destination.
 * 
 * @param source pointer to the source data to copy.
 * @param destination pointer to the destination data.
 * @return pointer to the destination data, result by the copying operation.
 */
char *copy(char *source, char *destination, size_t n_bytes)
{
    if (source == NULL || destination == NULL)
    {
        return NULL;
    }

    for (size_t index = 0; index < n_bytes || destination[index] != '\0'; index++)
    {
        destination[index] = source[index];
    }

    return destination;
}

/**
 * Returns a copy of the internal char sequence of the string.
 * 
 * @param pointer to string to extract the internal char sequence.
 * @return pointer to copy of internal character sequence of string.
 */
char *get_character_sequence (string_t *string)
{
    if (is_valid(string) == 1)
    {
        return clone(string->character_sequence, string->length);
    }

    return NULL;
}

/**
 * Returns a copy of the length of a string.
 * 
 * @param pointer to string to get the length.
 * @return copy of length of the string.
 */
uint8_t get_length (string_t *string)
{
    if (is_valid(string) == 1) 
    {
        return string->length;
    }

    return NULL;
}

/**
 * Checks if the string is valid or not.
 * 
 * @param pointer to string to check the validity.
 * @return copy of the validity field of the string.
 */
uint8_t is_valid (string_t *string)
{
    if (string != NULL) 
    {
        return string->valid;
    }

    return NULL;
}

string_t *create_from(uint8_t *input_string)
{
    return NULL;
}

string_t *destroy(string_t *input_string)
{
    return NULL;
}