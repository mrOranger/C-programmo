#include <stddef.h>

#include "string.h"

struct _string {
    char *character_sequence;
    size_t length;
    uint8_t valid:1;
};

char *get_character_sequence (string_t *string)
{
    if (is_valid(string) == 1)
    {
        return clone(string->character_sequence, string->length);
    }

    return NULL;
}

uint8_t get_length (string_t *string)
{
    if (is_valid(string) == 1)
    {
        return string->length;
    }

    return NULL;
}

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
    string_t *new_string = (string_t*)calloc(1, sizeof(string_t));

    if (new_string == NULL)
    {
        return NULL;
    }

    size_t internal_string_length = length(
}

string_t *destroy(string_t *input_string)
{
    return NULL;
}
