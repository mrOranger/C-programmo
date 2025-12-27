#include <stdio.h>
#include <stdlib.h>

#include "../../libs/client/client.h"
#include "../../libs/client_manager/client_manager.h"

struct _client_manager {
    size_t total_clients;
    client_t** clients;
};

client_manager_t* new_client_manager()
{
    client_manager_t* client_manager = (client_manager_t*)calloc(1, sizeof(client_manager_t));

    client_manager->total_clients = 0;
    client_manager->clients = (client_t**)calloc(100, sizeof(client_t*));

    return client_manager;
}

void save (const client_manager_t* client_manager)
{
    if (client_manager->total_clients == 0 || client_manager->clients == NULL)
    {
        return;
    }

    FILE* file_pointer = fopen("...", "a");

    if (file_pointer == NULL)
    {
        fprintf(stderr, "Error in opening file clients.dat!\n");
        exit(-1);
    }

    for (size_t index = 0; index < client_manager->total_clients; index++)
    {
        char* serialized_client = serialize_client(client_manager->clients[index]);
        fprintf(file_pointer, "%s\n", serialized_client);
    }

    if(fclose(file_pointer) != 0)
    {
        fprintf(stderr, "Error in closing file clients.dat!\n");
        exit(-1);
    }
}

void load ()
{
    FILE* file_pointer = fopen("...", "r");

    if (file_pointer == NULL)
    {
        fprintf(stderr, "Error in opening file clients.dat!\n");
        exit(-1);
    }

    char *tax_code, *first_name, *last_name;

    tax_code = (char*)calloc(100, sizeof(char));
    first_name = (char*)calloc(100, sizeof(char));
    last_name = (char*)calloc(100, sizeof(char));

    while (fscanf(file_pointer, "%99[^$]$%99[^$]$%99s\n", tax_code, first_name, last_name) == 3)
    {
        printf("[%s] - %s | %s\n", tax_code, first_name, last_name);
    }

    if(fclose(file_pointer) != 0)
    {
        fprintf(stderr, "Error in closing file clients.dat!\n");
        exit(-1);
    }
}

void register_client (client_manager_t* client_manager, const client_t* client)
{
    if (client == NULL)
    {
        return;
    }

    if (client_manager->clients == NULL)
    {
        return;
    }

    client_manager->clients[client_manager->total_clients++] = client;
}
