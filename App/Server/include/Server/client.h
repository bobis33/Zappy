/*
** EPITECH PROJECT, 2024
** Server
** File description:
** client
*/

#pragma once

#include <netinet/in.h>
#include <stdbool.h>

#include "Server/constant.h"
#include "Server/Game/game.h"

typedef enum identity_e {
    AI,
    GRAPHIC,
    NONE
} identity_t;

typedef struct data_s {
    int fd;
    identity_t identity;
} data_t;

typedef struct client_s {
    int max_fd;
    fd_set master_fds;
    fd_set read_fds;
    socklen_t client_len;
    struct sockaddr_in socket;
    data_t clients[MAX_CLIENTS];
} client_t;

bool create_client(client_t *client, int server_fd, int new_fd);
void remove_client(client_t *client, int fd);
data_t *get_client_by_fd(client_t *client, int fd);

bool client_inputs(game_t *game, client_t *client, int fd);
