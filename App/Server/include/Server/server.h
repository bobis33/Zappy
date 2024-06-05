/*
** EPITECH PROJECT, 2024
** zappy_server
** File description:
** server
*/

#pragma once

    #include <netinet/in.h>

    #include "Server/arguments.h"
    #include "client.h"

typedef struct server_s {
    int fd;
    uint16_t port;
    int max_clients;
    struct sockaddr_in socket;
    struct protoent *pe;
} server_t;

typedef enum server_status_e {
    RUNNING,
    STOPPED,
    STOPPED_ERROR
} server_status_t;

bool *stop_signal_catched(void);
bool run_server(arguments_t *args);
server_status_t server_inputs(void);
