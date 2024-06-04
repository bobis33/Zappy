/*
** EPITECH PROJECT, 2024
** Server
** File description:
** client
*/

#pragma once

    #include <netinet/in.h>

    #include "Server/constant.h"

typedef struct data_s {
    int fd;
    struct sockaddr_in socket;
} data_t;

typedef struct client_s {
    int max_fd;
    fd_set master_fds;
    fd_set read_fds;
    socklen_t client_len;
    struct sockaddr_in socket;
    data_t clients[MAX_CLIENTS];
} client_t;
