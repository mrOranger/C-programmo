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

void* create_empty()
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

void* create_from_string(void* string)
{
    if (string == NULL)
    {
        return NULL;
    }
    
    String* new_string = create_empty();

    if (valid(new_string) == 0)
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

size_t size(void* string)
{
    if (valid(string) == 0 || ((String*)string)->internal_string == NULL)
    {
        return 0;
    }

    size_t size_copy = ((String*)string)->size;

    return size_copy;
}

void* value(void* string)
{
    if (valid(string) == 0)
    {
        return 0;
    }

    if(size(string) == 0)
    {
        return "";
    }

    char* string_copy = (char*)calloc(size(string), sizeof(char));
    strcpy(string_copy, ((String*)string)->internal_string);

    return string_copy;
}

uint8_t valid(void* string)
{
    if (string == NULL)
    {
        return 0;
    }

    uint8_t valid_copy = ((String*)string)->valid;

    return valid_copy; 
}

uint8_t equals(void* first_string, void* second_string)
{
    if (valid(first_string) == 0 || valid(second_string) == 0)
    {
        return 0;
    }

    if (size(first_string) != size(second_string))
    {
        return 0;
    }

    for (uint8_t index = 0; index < size(first_string); index++)
    {
        char first_string_char  = ((String*)first_string)->internal_string[index];
        char second_string_char = ((String*)second_string)->internal_string[index];

        if (first_string_char != second_string_char) 
        {
            return 0;
        }
    }

    return 1;
}

uint8_t includes(void* string, void* search_string)
{
    if (
        valid(string) == 0 || 
        valid(search_string) == 0 || 
        size(search_string) == 0 ||
        size(string) < size(search_string)
    ) {
        return 0;
    }

    for (uint8_t index = 0; index < size(string); index++)
    {
        uint8_t matching_chars = 0;

        for (uint8_t search_index = 0; search_index < size(search_string); search_index++)
        {
            if (((String*)string)->internal_string[index + search_index] == ((String*)search_string)->internal_string[search_index])
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

uint8_t ends_with(void* string, void* search_string)
{
     if (
        valid(string) == 0 || 
        valid(search_string) == 0 || 
        size(search_string) == 0 ||
        size(string) < size(search_string)
    ) {
        return 0;
    }

    if (size(string) == 1)
    {
        return ((String*)search_string)->internal_string[0] == ((String*)string)->internal_string[0];
    }

    char* postfix           = (char*)calloc(size(search_string), sizeof(char));
    uint8_t postfix_index   = size(search_string) - 1;
    uint8_t string_index    = size(string) - 1;

    if (postfix == NULL)
    {
        return 0;
    }

    for (u_int8_t index = 0; index < size(search_string); index++)
    {
        postfix[postfix_index]  = ((String*)string)->internal_string[string_index];
        postfix_index           = postfix_index - 1;
        string_index            = string_index - 1;
    }

    for (u_int8_t index = 0; index < size(search_string); index++)
    {
        if (postfix[index] != ((String*)search_string)->internal_string[index])
        {
            free(postfix);
            return 0;      
        }
    }

    free(postfix);
    return 1;
}

uint8_t starts_with(void* string, void* search_string)
{
    if (
        valid(string) == 0 || 
        valid(search_string) == 0 || 
        size(search_string) == 0 || 
        size(string) < size(search_string)
    ) {
        return 0;
    }


    for (uint8_t index = 0; index < size(search_string); index++)
    {
        if (((String*)search_string)->internal_string[index] != ((String*)string)->internal_string[index])
        {
            return 0;
        }
    }

    return 1;
}

void* at(void* string, size_t index)
{
    if (valid(string) == 0 || (size(string) - 1) < index || ((String*)string)->internal_string == NULL)
    {
        return NULL;
    }

    String* new_string = (String*)calloc(1, sizeof(String));

    if (new_string == NULL)
    {
        return NULL;
    }
    
    new_string->internal_string     = (char*)calloc(2, sizeof(char));
    new_string->internal_string[0]  = ((String*)string)->internal_string[index];
    new_string->internal_string[1]  = '\0';
    new_string->valid               = 1;
    new_string->size                = 1;

    return new_string;
}

void* upper(void* string)
{
    if (valid(string) == 0)
    {
        return NULL;
    }

    String* new_string = create_from_string(value(string));

    if (new_string == NULL)
    {
        return NULL;
    }

    for (uint8_t index = 0; index < size(new_string); index++)
    {
        if (new_string->internal_string[index] >= 97 && new_string->internal_string[index] <= 122)        
        {
            new_string->internal_string[index] = new_string->internal_string[index] - 32;
        }
    }

    return new_string;
}

void* lower(void* string)
{
    if (valid(string) == 0)
    {
        return NULL;
    }

    String* new_string = create_from_string(value(string));

    if (new_string == NULL)
    {
        return NULL;
    }    

    for (uint8_t index = 0; index < size(new_string); index++)
    {
        if (new_string->internal_string[index] >= 65 && new_string->internal_string[index] <= 90)
        {
            new_string->internal_string[index] = new_string->internal_string[index] + 32;
        }
    }

    return new_string;
}

void* concat(void* string, void* concat_string)
{
    if (valid(string) == 0 || valid(concat_string) == 0)
    {
        return NULL;
    }

    char* from_string   = ((String*)string)->internal_string;
    char* to_string     = ((String*)concat_string)->internal_string;
    String* new_string  = create_from_string(from_string);

    if (new_string == NULL)
    {
        return NULL;
    }

    new_string->internal_string = strcat(new_string->internal_string, to_string);
    new_string->size            = ((String*)string)->size + ((String*)concat_string)->size;
    new_string->valid           = 1;

    return new_string;
}

int32_t index_of(void* string, void* search_string)
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
            if (((String*)string)->internal_string[index + search_index] == ((String*)search_string)->internal_string[search_index])
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

void* repeat(void* string, uint8_t count)
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

    repeated_string->internal_string    = (char*)calloc(1 + ((String*)string)->size * count, sizeof(char));
    repeated_string->size               = ((String*)string)->size * count;
    repeated_string->valid              = 1;

    for (uint8_t repetition = 0; repetition < count; repetition++)
    {
        for (uint8_t index = 0; index < size(string); index++)
        {
            repeated_string->internal_string[((size(string)) * repetition) + index] = ((String*)string)->internal_string[index];
        }
    }

    return repeated_string;
} 

void* replace(void* input_string, void* replace_pattern, void* string_to_replace)
{
    if (valid(input_string) == 0 || valid(replace_pattern) == 0 || valid(string_to_replace) == 0)
    {
        return NULL;
    }

    if (size(string_to_replace) == 0)
    {
        return create_from_string(((String*) input_string)->internal_string);
    }

    const int32_t replace_index = index_of(input_string, replace_pattern);

    if (replace_index == -1) {
        return create_from_string(value(input_string));
    }

    if (size(string_to_replace) == size(replace_pattern)) 
    {
        size_t string_to_replace_index = 0;
        char* new_string = (char*)calloc(size(input_string) + 1, sizeof(char));

        for (size_t index = 0; index < size(input_string); index++)
        {
            if (index >= replace_index && string_to_replace_index < size(replace_pattern))
            {
                new_string[index] = ((String*)string_to_replace)->internal_string[string_to_replace_index++];

                continue;
            }

            new_string[index] = ((String*)input_string)->internal_string[index];

            continue;
        }

        return create_from_string(new_string);
    }

    if (size(string_to_replace) > size(replace_pattern)) 
    {
        size_t prefix_index = 0;
        size_t string_index = 0;
        size_t postfix_index = replace_index + size(replace_pattern);

        size_t new_string_chars = size(string_to_replace) - size(replace_pattern);

        char* new_string = (char*)calloc(size(input_string) + new_string_chars + 1, sizeof(char));

        for (size_t index = 0; index < size(input_string) + new_string_chars; index++)
        {
            if (index < replace_index)
            {
                new_string[index] = ((String*)input_string)->internal_string[prefix_index++];

                continue;
            }

            if (index >= replace_index + size(string_to_replace))
            {
                new_string[index] = ((String*)input_string)->internal_string[postfix_index++];

                continue;
            }

            new_string[index] = ((String*)string_to_replace)->internal_string[string_index++];
        }

        return create_from_string(new_string);
    }

    if (size(string_to_replace) < size(replace_pattern)) 
    {        
        size_t prefix_index = 0;
        size_t string_index = 0;
        size_t postfix_index = replace_index + size(replace_pattern);

        size_t missing_chars = size(replace_pattern) - size(string_to_replace);

        char* new_string = (char*)calloc(size(input_string) - missing_chars + 1, sizeof(char));

        for (size_t index = 0; index < size(input_string) - missing_chars; index++)
        {
            if (index < replace_index)
            {
                new_string[index] = ((String*)input_string)->internal_string[prefix_index++];

                continue;
            }

            if (index >= replace_index + size(string_to_replace))
            {
                new_string[index] = ((String*)input_string)->internal_string[postfix_index++];

                continue;
            }

            new_string[index] = ((String*)string_to_replace)->internal_string[string_index++];
        }

        return create_from_string(new_string);
    }

    return NULL;
}

void destroy(void* string)
{
    if (valid(string) == 1)
    {
        free(((String*)string)->internal_string);
        ((String*)string)->size = 0;
        ((String*)string)->valid = 0;

        free(string);
    }
}

size_t string_length(void* source)
{
    if (source == NULL)
    {
        return 0;
    }

    size_t length = 0;

    for (size_t index = 0; ((char*)source)[index] != '\0'; index = index + 1)
    {
        length = length + 1;
    }

    return length;
}

void* string_copy(void* source, size_t n_bytes)
{
    if (source == NULL || n_bytes == 0)
    {
        return NULL;
    }

    size_t bytes_to_copy = n_bytes;
    size_t length = string_length(source);

    if (length < n_bytes)
    {
        bytes_to_copy = length;
    }

    char* destination = (char*)calloc(bytes_to_copy + 1, sizeof(char));

    for (size_t index = 0; index < bytes_to_copy; index = index + 1)
    {
        destination[index] = ((char*)source)[index];
    }

    return destination;
}

void* string_ncopy (void* source, size_t n_bytes, size_t start_index)
{
    if (source == NULL || n_bytes == 0) 
    {
        return NULL;
    }

    size_t length = string_length(source);

    if (start_index > length)
    {
        return NULL;
    }

    if (n_bytes > length)
    {
        return string_copy(source, length);
    }

    if (start_index == 0)
    {
        return string_copy(source, n_bytes);
    }

    char* destination = (char*)calloc(n_bytes, sizeof(char));
    size_t destination_index = 0;

    for (size_t index = start_index; destination_index < n_bytes; index = index + 1)
    {
        destination[destination_index++] = ((char*)source)[index];
    }

    return destination;
}