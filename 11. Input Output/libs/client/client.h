#ifndef CLIENT_H
#define CLIENT_H

typedef struct _client client_t;

client_t* new_client(const char* tax_code, const char* first_name, const char* last_name);

char* get_tax_code(const client_t* client);
char* get_first_name(const client_t* client);
char* get_last_name(const client_t* client);

void set_tax_code(client_t* client, const char* tax_code);
void set_first_name(client_t* client, const char* first_name);
void set_last_name(client_t* client, const char* last_name);

client_t* destroy_client(client_t* client);

#endif
