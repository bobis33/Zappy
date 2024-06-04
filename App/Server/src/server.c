/*
** EPITECH PROJECT, 2024
** zappy_server
** File description:
** server
*/

#include <stdbool.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "Server/arguments.h"
#include "Server/server.h"
#include "Server/constant.h"
#include "Server/client.h"

static void remove_client(client_t *client, int fd)
{
    close(fd);
    FD_CLR(fd, &client->master_fds);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client->clients[i].fd == fd) {
            client->clients[i].fd = -1;
        }
    }
}

int handle_inputs(
        client_t *client,
        const int fd)
{
    char buffer[1024] = "\0";
    int buffer_size = sizeof(buffer);
    ssize_t read_value = read(fd, buffer, buffer_size);

    switch (read_value) {
        case -1:
            perror("read");
            return ERROR;
        case 0:
            close(fd);
            remove_client(client, fd);
            break;
        default:
            write(1, "ok\n", 3);
            return EPITECH_EXIT_SUCCESS;
    }
    return EPITECH_EXIT_SUCCESS;
}




static data_t *get_client_by_fd(client_t *client, int fd)
{
    for (register int index = 0; index < MAX_CLIENTS; index++) {
        if (client->clients[index].fd == fd) {
            return &client->clients[index];
        }
    }
    return NULL;
}


static bool create_new_client(client_t *client, int new_fd)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client->clients[i].fd == -1) {
            client->clients[i].fd = new_fd;
            FD_SET(new_fd, &client->master_fds);
            write(new_fd, "Connected\n", strlen("Connected\n"));
            return true;
        }
    }
    return false;
}

static bool handle_clients(server_t *server)
{
    char *cmd = NULL;
    size_t len = 0;
    int nfds = 0;
    int rv_select = 0;
    client_t *client = malloc(sizeof(client_t));
    if (!client) {
        perror("malloc");
        return false;
    }
    client->client_len = sizeof(client->socket);
    FD_ZERO(&client->master_fds);
    FD_SET(server->fd, &client->master_fds);
    FD_SET(STDIN_FILENO, &client->master_fds);
    client->max_fd = server->fd;
    memset(client->clients, 0, sizeof(client->clients));

    for (int i = 0; i < MAX_CLIENTS; i++) {
        client->clients[i].fd = -1;
    }

    while (true) {
        nfds = client->max_fd + 1;
        client->read_fds = client->master_fds;
        rv_select = select(nfds, &client->read_fds, NULL, NULL, NULL);
        if (rv_select == ERROR) {
            perror("select");
            free(client);
            return false;
        }

        for (int i = 0; i <= client->max_fd; i++) {
            data_t *current_client = NULL;
            if (FD_ISSET(i, &client->read_fds)) {
                if (i == server->fd) {
                    int new_fd = accept(server->fd, (struct sockaddr *) &client->socket, &client->client_len);
                    if (new_fd == ERROR) {
                        perror("accept");
                        free(client);
                        return false;
                    }
                    if (client->clients[MAX_CLIENTS - 1].fd != -1) {
                        close(new_fd);
                        return ERROR;
                    }
                    if (new_fd > client->max_fd) {
                        client->max_fd = new_fd;
                    }
                    if (!create_new_client(client, new_fd)) {
                        free(client);
                        return false;
                    }
                } else if (i == STDIN_FILENO) {

                    if (getline(&cmd, &len, stdin) == -1) {
                        perror("getline");
                        free(client);
                        return false;
                    }
                    if (strcmp(cmd, "quit\r\n") == 0) {
                        free(client);
                        return true;
                    }
                } else {
                    // ICI
                    current_client = get_client_by_fd(client, i);
                    if (!current_client) {
                        remove_client(client, i);
                        break;
                    }
                    if (handle_inputs(client, i) == -1) {
                        remove_client(client, i);
                    }
                }
            }
        }
    }
    free(client);
}

static bool handle_server(server_t *server)
{
    server->fd = socket(AF_INET, SOCK_STREAM, server->pe->p_proto);
    if (server->fd == ERROR) {
        perror("socket");
        return false;
    }
    if (bind(server->fd, (const struct sockaddr *)&server->socket, sizeof(struct sockaddr_in)) == ERROR) {
        perror("bind");
        return false;
    }
    if (listen(server->fd, server->max_clients) == ERROR) {
        perror("listen");
        close(server->fd);
        return false;
    }
    return true;
}

bool run_server(arguments_t *args)
{
    struct protoent proto;
    struct protoent *proto_ptr = NULL;
    char buffer[MAX_BUFFER_SIZE];
    server_t *server = malloc(sizeof(server_t));
    if (!server) {
        perror("malloc");
        return false;
    }
    server->port = args->port;
    server->max_clients = args->clients_nb * args->nb_teams;
    server->socket.sin_family = AF_INET;
    server->socket.sin_port = htons(server->port);
    server->socket.sin_addr.s_addr = INADDR_ANY;
    if (getprotobyname_r("TCP", &proto, buffer, sizeof(buffer), &proto_ptr) != EXIT_SUCCESS) {
        free(server);
        return false;
    }
    server->pe = proto_ptr;
    if (!handle_server(server) || !handle_clients(server)) {
        free(server);
        return false;
    }
    return true;
}
