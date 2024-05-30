/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** bind
*/

#include <stdlib.h>
#include <stdbool.h>

#include "Server/server.h"

bool bind_port(server_t *server, char *arg)
{
    server->port = atoi(arg);
    return true;
}

bool bind_width(server_t *server, char *arg)
{
    server->width = atoi(arg);
    return true;
}

bool bind_height(server_t *server, char *arg)
{
    server->height = atoi(arg);
    return true;
}

bool bind_clients_nb(server_t *server, char *arg)
{
    server->clients_nb = atoi(arg);
    return true;
}

bool bind_freq(server_t *server, char *arg)
{
    server->freq = atoi(arg);
    return true;
}
