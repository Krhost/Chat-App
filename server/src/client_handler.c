#include "../include/inc.h"

void broadcast_message(char *message, int socket_client)
{
    for (int i = 0; i < nbr_client; i++)
    {
        if (clients[i].socket != socket_client)
        {
            if (write(clients[i].socket, message, strlen(message)) < 0)
            {
                perror("Erreur d'écriture du message");
            }
        }
    }
}

void *handle_client(void *socket_desc)
{
    int socket_client = *(int *)socket_desc;
    free(socket_desc);

    char buf[BUF_SIZE];
    int message_len;

    while ((message_len = read(socket_client, buf, BUF_SIZE - 1)) > 0)
    {
        buf[message_len] = '\0';
        broadcast_message(buf, socket_client);
    }

    // Remove client
    for (int i = 0; i < nbr_client; i++)
    {
        if (clients[i].socket == socket_client)
        {
            for (int j = i; j < nbr_client - 1; j++)
            {
                clients[j] = clients[j + 1];
            }
            nbr_client--;
            break;
        }
    }

    close(socket_client);
    return NULL;
}

void ajout_client(int socket_client, struct sockaddr_in client_addr, struct Client *clients, int *nbr_client)
{
    clients[*nbr_client].socket = socket_client;
    clients[*nbr_client].ip = client_addr.sin_addr.s_addr;
    clients[*nbr_client].port = ntohs(client_addr.sin_port);

    pthread_t thread;
    int *socket_ptr = malloc(sizeof(int));
    *socket_ptr = socket_client;

    if (pthread_create(&thread, NULL, handle_client, socket_ptr))
    {
        perror("Erreur création thread");
        close(socket_client);
        free(socket_ptr);
        exit(EXIT_FAILURE);
    }
    else
    {
        pthread_detach(thread);
    }
    (*nbr_client)++;
}

void client_excess(int socket_client)
{
    char *message = "Server is full";
    if (write(socket_client, message, strlen(message)) < 0)
    {
        perror("Erreur d'écriture du message");
        close(socket_client);
    }
    close(socket_client);
}