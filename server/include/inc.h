#ifndef INC_H
#define INC_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>

#define MAX_CLIENTS 10
#define BUF_SIZE 1024
#define BUF_FILE_SIZE 15728640

// Client structure
struct Client
{
    char *pseudo; // Client's pseudonym
    int socket;   // Client's socket file descriptor
    int ip;       // Client's IP address
    int port;     // Client's port
};

// External variables
extern struct Client clients[MAX_CLIENTS];
extern int nbr_client;

// Function declarations

/**
 * @brief Handles Ctrl + C interrupt signal to stop the server gracefully
 */
void sigint_handler();

/**
 * @brief Informs a client that there is no more space on the server
 *
 * @param socket_client Client's socket file descriptor
 */
void client_excess(int socket_client);

/**
 * @brief Handles a client, reads messages, and performs appropriate actions
 *
 * @param socket_desc Pointer to the client's socket descriptor
 * @return NULL (thread function)
 */
void *handle_client(void *socket_desc);

/**
 * @brief Broadcasts a message sent by a user to other users
 *
 * @param message The message to broadcast
 * @param socket_client Client's socket descriptor
 */
void broadcast_message(char *message, int socket_client);

/**
 * @brief Adds a new client to the list of clients
 *
 * @param socket_client Descriptor of the new client's socket
 * @param client_addr Structure containing the client's address information
 * @param clients Array of client structures
 * @param nbr_client Pointer to the current number of clients
 */
void ajout_client(int socket_client, struct sockaddr_in client_addr, struct Client *clients, int *nbr_client);

#endif
