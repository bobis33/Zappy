/*
** EPITECH PROJECT, 2024
** zappy_server
** File description:
** server
*/

#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "Server/server.h"
#include "Server/tools.h"

static bool open_server(server_t *server)
{
    server->fd = socket(AF_INET, SOCK_STREAM, server->pe->p_proto);
    if (is_perror(server->fd, "socket")){
        return false;
    }
    if (is_perror(bind(server->fd,
        (const struct sockaddr *)&server->socket,
        sizeof(struct sockaddr_in)), "bind")) {
        return false;
    }
    if (is_perror(
            listen(server->fd, server->max_clients), "listen")) {
        close(server->fd);
        return false;
    }
    return true;
}

static bool init_server(server_t *server, arguments_t *args)
{
    struct protoent proto;
    struct protoent *proto_ptr = NULL;
    char buffer[MAX_BUFFER_SIZE];

    server->port = args->port;
    server->max_clients = args->clients_nb * args->nb_teams;
    server->socket.sin_family = AF_INET;
    server->socket.sin_port = htons(server->port);
    server->socket.sin_addr.s_addr = INADDR_ANY;
    if (getprotobyname_r("TCP",
        &proto,
        buffer,
        sizeof(buffer),
        &proto_ptr) != EXIT_SUCCESS) {
        return false;
    }
    server->pe = proto_ptr;
    return true;
}

static client_t *init_client_data(int server_fd)
{
    client_t *client = malloc(sizeof(client_t));

    if (!client) {
        perror("malloc");
        return false;
    }
    client->client_len = sizeof(client->socket);
    FD_ZERO(&client->master_fds);
    FD_SET(server_fd, &client->master_fds);
    FD_SET(STDIN_FILENO, &client->master_fds);
    client->max_fd = server_fd;
    memset(client->clients, 0, sizeof(client->clients));
    for (int i = 0; i < MAX_CLIENTS; i++) {
        client->clients[i].fd = ERROR;
    }
    return client;
}

static bool main_loop(server_t *server)
{
    int nb_fds = 0;
    int rv_select = 0;
    int new_fd = 0;
    client_t *client = init_client_data(server->fd);
    data_t *current_client = NULL;

    while (true) {
        nb_fds = client->max_fd + 1;
        client->read_fds = client->master_fds;
        rv_select = select(nb_fds, &client->read_fds, NULL, NULL, NULL);
        if (rv_select == ERROR) {
            perror("select");
            free(client);
            return false;
        }
        for (int i = 0; i <= client->max_fd; i++) {
            if (FD_ISSET(i, &client->read_fds)) {
                if (i == server->fd) {
                    if (!create_client(client, server->fd, new_fd)) {
                        free(client);
                        return false;
                    }
                } else if (i == STDIN_FILENO) {
                    if (server_inputs() == STOPPED) {
                        FD_CLR(server->fd, &client->master_fds);
                        close(server->fd);
                        free(client);
                        return true;
                    }
                } else {
                    current_client = NULL;
                    current_client = get_client_by_fd(client, i);
                    if (!current_client || !client_inputs(i)) {
                        remove_client(client, i);
                    }
                }
            }
        }
    }
    return true;
}

bool run_server(arguments_t *args)
{
    server_t *server = malloc(sizeof(server_t));

    if (!server) {
        perror("malloc");
        return false;
    }
    if (!init_server(server, args) ||
        !open_server(server) ||
        !main_loop(server)) {
        free(server);
        return false;
    }
    return true;
}
