#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H

#include "../client/client.h"

typedef struct _client_manager Client_Manager;

void save (const client_manager_t* client_manager);
client_manager_t load ();

void register_client (client_manager_t* client_manager, const client_t* client);
void update_client (client_manager_t* client_manager, const client_t* client);
void delete_client (client_manager_t* client_manager, const client_t* client);

#endif
