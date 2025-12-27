#include <stdio.h>

#include "./libs/client/client.h"
#include "./libs/client_manager/client_manager.h"

int main (const int argc, const char** argv)
{
    client_manager_t* client_manager = new_client_manager();

    register_client(client_manager, new_client("AAAAAA00A00A000A", "Mario", "Rossi"));
    register_client(client_manager, new_client("AAAAAA00A00A000B", "Maria", "Verdi"));
    register_client(client_manager, new_client("AAAAAA00A00A000C", "Francesco", "Neri"));
    register_client(client_manager, new_client("AAAAAA00A00A000D", "Francesca", "Bruni"));

    load();

    return 0;
}
