#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>

#include "string.h"

struct _string {
    char*   internal_string;
    size_t  size;
    uint8_t valid:2;
};

String* create()
{
    String* new_string = (String*)calloc(1, sizeof(String));

    if (valid(new_string))
    {
        return NULL;
    }

    new_string->internal_string = NULL;
    new_string->size            = 0;
    new_string->valid           = 1;

    return new_string;
}

String* create_string(char* string)
{
    String* new_string = create();

    if (new_string == NULL || valid(new_string) == 0)
    {
        return NULL;
    }

    size_t string_length = strlen(string);

    if (string_length >= UINT8_MAX)
    {
        return NULL;
    }

    new_string->internal_string = (char*)calloc(string_length, sizeof(char));
    new_string->size = string_length;
    new_string->valid = 1;

    strcpy(new_string->internal_string, string);

    return new_string;
}

size_t size(String* string)
{
    if (valid(string) == 0)
    {
        return 0;
    }

    return string->size;
}

char* value(String* string)
{
    if (valid(string) == 0)
    {
        return 0;
    }

    return string->internal_string;
}

uint8_t valid(String* string)
{
    if (string == NULL)
    {
        return 0;
    }

    return string->valid;

}

String* at(String* string, size_t index)
{
    if (valid(string) == 0 || size(string) < index || string->internal_string == NULL)
    {
        return NULL;
    }

    String* new_string = (String*)calloc(1, sizeof(String));

    if (new_string == NULL)
    {
        return NULL;
    }
    
    new_string->internal_string     = (char*)calloc(2, sizeof(char));
    new_string->internal_string[0]  = string->internal_string[index];
    new_string->internal_string[1]  = '\0';
    new_string->valid               = 1;
    new_string->size                = 1;

    return new_string;
}

String* concat(String* string, String* concat_string)
{
    if (string == NULL || valid(string) == 0)
    {
        return NULL;
    }

    if (concat_string == NULL || valid(concat_string) == 0)
    {
        String* string_copy = create();

        strcpy(string_copy->internal_string, string->internal_string);

        string_copy->size   = string->size;
        string_copy->valid  = 1;

        return string_copy;
    }

    char* from_string   = string->internal_string;
    char* to_string     = concat_string->internal_string;

    String* new_string              = create_string(from_string);
    new_string->internal_string     = strcat(new_string->internal_string, to_string);
    new_string->size                = string->size + concat_string->size;
    new_string->valid               = 1;

    return new_string;
}

String* upper(String* string)
{
    if (valid(string) == 0)
    {
        return NULL;
    }

    for (uint8_t index = 0; index < size(string); index++)
    {
        if (string->internal_string[index] >= 65 && string->internal_string[index] <= 90)
        {
            string->internal_string[index] = string->internal_string[index] + 32;
        }
    }

    return string;
}

String* lower(String* string)
{
    if (valid(string) == 0)
    {
        return NULL;
    }

    for (uint8_t index = 0; index < size(string); index++)
    {
        if (string->internal_string[index] >= 97 && string->internal_string[index] <= 122)
        {
            string->internal_string[index] = string->internal_string[index] - 32;
        }
    }

    return string;
}

uint8_t ends_with(String* string, String* search_string)
{
     if (
        valid(string) == 0 || 
        valid(search_string) == 0 || 
        size(search_string) == 0 ||
        size(string) < size(search_string)
    )
    {
        return 0;
    }


    for (uint8_t index = 0; index < size(search_string); index++)
    {
        if (search_string->internal_string[index] != string->internal_string[index + size(search_string)])
        {
            return 0;
        }
    }

    return 1;
}

uint8_t starts_with(String* string, String* search_string)
{
    if (
        valid(string) == 0 || 
        valid(search_string) == 0 || 
        size(search_string) == 0 ||
        size(string) < size(search_string)
    )
    {
        return 0;
    }


    for (uint8_t index = 0; index < size(search_string); index++)
    {
        if (search_string->internal_string[index] != string->internal_string[index])
        {
            return 0;
        }
    }

    return 1;
}

uint8_t includes(String* string, String* search_string)
{
    if (
        valid(string) == 0 || 
        valid(search_string) == 0 || 
        size(search_string) == 0 ||
        size(string) < size(search_string)
    )
    {
        return 0;
    }

    for (uint8_t index = 0; index < size(string); index++)
    {
        uint8_t matching_chars = 0;

        for (uint8_t search_index = 0; search_index < size(search_string); search_index++)
        {
            if (string->internal_string[index + search_index] == search_string->internal_string[search_index])
            {
                matching_chars = matching_chars + 1;
            }

            if (matching_chars == size(search_string))
            {
                return 1;
            }
        }
    }
    
    return 0;
}

int32_t index_of(String* string, String* search_string)
{
    if (includes(string, search_string) == 0)
    {
        return -1;
    }

    for (uint8_t index = 0; index < size(string); index++)
    {
        uint8_t matching_chars = 0;

        for (uint8_t search_index = 0; search_index < size(search_string); search_index++)
        {
            if (string->internal_string[index + search_index] == search_string->internal_string[search_index])
            {
                matching_chars = matching_chars + 1;
            }

            if (matching_chars == size(search_string))
            {
                return index;
            }
        }
    }
    
    return 0;
}

String* repeat(String* string, uint8_t count)
{
    if (valid(string) == 0)
    {
        return NULL;
    }

    String* repeated_string = (String*)calloc(1, sizeof(String));

    if (repeated_string == NULL)
    {
        return NULL;
    }

    repeated_string->internal_string    = (char*)calloc(1 + string->size * count, sizeof(char));
    repeated_string->size               = string->size * count;
    repeated_string->valid              = 1;

    for (uint8_t repetition = 0; repetition < count; repetition++)
    {
        for (uint8_t index = 0; index < size(string); index++)
        {
            repeated_string->internal_string[((size(string)) * repetition) + index] = string->internal_string[index];
        }
    }

    return repeated_string;
}

void destroy(String* string)
{
    if (valid(string) == 1)
    {
        free(string->internal_string);
        string->size = 0;
        string->valid = 0;

        free(string);
    }
}