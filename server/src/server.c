#include "../include/inc.h"

struct Client clients[MAX_CLIENTS];
int nbr_client = 0;

int main()
{
    int socket_server = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_server == -1)
    {
        perror("Erreur création socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(1234);
    addr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    if (bind(socket_server, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) == -1)
    {
        perror("Erreur bind");
        close(socket_server);
        exit(EXIT_FAILURE);
    }

    // Set socket
    int opt = 1;
    if (setsockopt(socket_server, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1)
    {
        perror("Erreur setsockopt");
        close(socket_server);
        exit(EXIT_FAILURE);
    }

    if (listen(socket_server, 10) < 0)
    {
        perror("Erreur d'ecoute");
        close(socket_server);
        exit(EXIT_FAILURE);
    }

    signal(SIGINT, sigint_handler);

    while (1)
    {
        int socket_client;
        struct sockaddr_in client_addr;
        socklen_t len = sizeof(client_addr);

        socket_client = accept(socket_server, (struct sockaddr *)&client_addr, &len);
        if (socket_client < 0)
        {
            perror("Erreur d'attente de connexion");
            continue;
        }

        if (nbr_client < MAX_CLIENTS)
        {
            ajout_client(socket_client, client_addr, clients, &nbr_client);
        }
        else
        {
            client_excess(socket_client);
        }
    }

    close(socket_server);
    return 0;
}