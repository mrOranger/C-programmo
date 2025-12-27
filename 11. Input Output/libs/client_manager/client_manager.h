#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H

#include "../client/client.h"

typedef struct _client_manager client_manager_t;

client_manager_t* new_client_manager();
void save (const client_manager_t* client_manager);
void load ();

void register_client (client_manager_t* client_manager, const client_t* client);

#endif
