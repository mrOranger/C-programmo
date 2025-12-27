#include <stdio.h>

#include "./libs/client/client.h"

int main (const int argc, const char** argv)
{
    client_t* client = new_client("RNGDRD96D05A662T", "Mario", "Rossi");

    return 0;
}
