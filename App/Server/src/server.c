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

static bool connect_socket(server_t *server)
{
    struct protoent proto;
    struct protoent *proto_ptr = NULL;
    char buffer[MAX_BUFFER_SIZE];

    if (getprotobyname_r("TCP",
        &proto,
        buffer,
        sizeof(buffer),
        &proto_ptr) != EXIT_SUCCESS) {
        return false;
    }
    server->pe = proto_ptr;
    server->fd = socket(AF_INET, SOCK_STREAM, server->pe->p_proto);
    if (is_perror(server->fd, "socket")){
        return false;
    }
    return true;
}

static bool init_server(server_t *server, arguments_t *args)
{
    server->game = NULL;
    server->port = args->port;
    server->max_clients = args->clients_nb * args->nb_teams;
    server->socket.sin_family = AF_INET;
    server->socket.sin_port = htons(server->port);
    server->socket.sin_addr.s_addr = INADDR_ANY;
    if (!start_game(args, &server->game)) {
        return false;
    }
    return connect_socket(server);
}

static client_t *init_client_data(int server_fd)
{
    client_t *client = malloc(sizeof(client_t));

    if (!client) {
        perror("malloc");
        return NULL;
    }
    client->client_len = sizeof(client->socket);
    FD_ZERO(&client->master_fds);
    FD_SET(server_fd, &client->master_fds);
    FD_SET(STDIN_FILENO, &client->master_fds);
    client->max_fd = server_fd;
    memset(client->clients, 0, sizeof(client->clients));
    for (int i = 0; i < MAX_CLIENTS; i++) {
        client->clients[i].fd = ERROR;
        client->clients[i].identity = NONE;
    }
    return client;
}

static void viva_el_coding_style(client_t *client, server_t *server, int fd)
{
    data_t *current_client = get_client_by_fd(client, fd);

    if (fd != server->fd && fd != STDIN_FILENO) {
        if (!current_client || !client_inputs(server->game, client, fd)) {
            remove_client(client, fd);
        }
    }
}

static server_status_t loop_fds(client_t *client, server_t *server)
{
    int new_fd = 0;

    for (int index_fd = 0; index_fd <= client->max_fd; index_fd++) {
        if (!FD_ISSET(index_fd, &client->read_fds)) {
            continue;
        }
        if (index_fd == server->fd &&
            !create_client(client, server->fd, new_fd)) {
            free(client);
            return STOPPED_ERROR;
        }
        if (index_fd == STDIN_FILENO && server_inputs() == STOPPED) {
            FD_CLR(server->fd, &client->master_fds);
            close(server->fd);
            free(client);
            return STOPPED;
        }
        viva_el_coding_style(client, server, index_fd);
    }
    return RUNNING;
}

static bool main_loop(server_t *server)
{
    struct timeval timeout = {1, 0};
    client_t *client = init_client_data(server->fd);

    while (!*stop_signal_catched()) {
        client->read_fds = client->master_fds;
        if (select(client->max_fd + 1,
            &client->read_fds, NULL, NULL, &timeout) < 0) {
            free(client);
            return true;
        }
        switch (loop_fds(client, server)) {
            case STOPPED:
                return true;
            case STOPPED_ERROR:
                return false;
            default:
                break;
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
    free_game_resources(server->game);
    free(server);
    return true;
}
