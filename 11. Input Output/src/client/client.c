#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "../../libs/client/client.h"

struct _client {
    char* tax_code;
    char* first_name;
    char* last_name;
    uint8_t is_valid:2;
};

static size_t string_length(const char* source)
{
    if (source == NULL)
    {
        return 0;
    }

    size_t length = 0;

    for (size_t index = 0; source[index] != '\0'; index = index + 1)
    {
        length = length + 1;
    }

    return length;
}

static char* string_copy(const char* source, size_t n_bytes)
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
        destination[index] = source[index];
    }

    return destination;
}

static char* string_ncopy (const char* source, size_t n_bytes, size_t start_index)
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

client_t* new_client (const char* tax_code, const char* first_name, const char* last_name) 
{
    if (tax_code == NULL || first_name == NULL || last_name == NULL)
    {
        return NULL;
    }

    if (string_length(tax_code) != 16)
    {
        return NULL;
    }

    client_t* client = (client_t*)calloc(1, sizeof(client_t));

    client->tax_code = string_copy(tax_code, string_length(tax_code));
    client->first_name = string_copy(first_name, string_length(first_name));
    client->last_name = string_copy(last_name, string_length(last_name));
    client->is_valid = 1;

    return client;
}

char* get_tax_code (const client_t* client)
{
    if (client == NULL || client->is_valid == 0)
    {
        return NULL;
    }

    const size_t tax_code_length = string_length(client->tax_code);
    char* tax_code_copy = string_copy(client->tax_code, tax_code_length);

    return tax_code_copy;
}

char* get_first_name(const client_t* client)
{
    if (client == NULL || client->is_valid == 0)
    {
        return NULL;
    }

    const size_t first_name_length = string_length(client->first_name);
    char* first_name_copy = string_copy(client->first_name, first_name_length);

    return first_name_copy;
}

char* get_last_name(const client_t* client)
{
    if (client == NULL || client->is_valid == 0)
    {
        return NULL;
    }

    const size_t last_name_length = string_length(client->last_name);
    char* last_name_copy = string_copy(client->last_name, last_name_length);

    return last_name_copy;
}

void set_tax_code(client_t* client, const char* tax_code)
{
    if (client == NULL || client->is_valid == 0)
    {
        return;
    }
    
    const size_t tax_code_length = string_length(tax_code);
    char* tax_code_copy = string_copy(tax_code, tax_code_length);

    client->tax_code = tax_code_copy;
}

void set_first_name(client_t* client, const char* first_name)
{
    if (client == NULL || client->is_valid == 0)
    {
        return;
    }
    
    const size_t first_name_length = string_length(first_name);
    char* first_name_copy = string_copy(first_name, first_name_length);

    client->first_name= first_name_copy;
}

void set_last_name(client_t* client, const char* last_name)
{
    if (client == NULL || client->is_valid == 0)
    {
        return;
    }
    
    const size_t last_name_length = string_length(last_name);
    char* last_name_copy = string_copy(last_name, last_name_length);

    client->last_name = last_name_copy;
}

char* serialize_client (const client_t* client)
{
    if (client == NULL || client->is_valid == 0)
    {
        return NULL;
    }

    const size_t tax_code_length = string_length(client->tax_code);
    const size_t first_name_length = string_length(client->first_name);
    const size_t last_name_length = string_length(client->last_name);
    
    char* serialization_string = (char*)calloc(tax_code_length + first_name_length + last_name_length + 3, sizeof(char));

    sprintf(serialization_string, "%s$%s$%s", client->tax_code, client->first_name, client->last_name);

    return serialization_string;
}

client_t* destroy_client (client_t* client)
{
    if (client->is_valid == 1)
    {
        client->is_valid = 0;

        free(client->tax_code);
        free(client->first_name);
        free(client->last_name);
        free(client);

        return client;
    }

    return client;
}
