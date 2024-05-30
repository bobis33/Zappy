/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** bind.h
*/

#pragma once

#include <stdbool.h>

#include "Server/server.h"

bool bind_port(server_t *server, char *arg);
bool bind_width(server_t *server, char *arg);
bool bind_height(server_t *server, char *arg);
bool bind_team(server_t *server, char *arg);
bool bind_clients_nb(server_t *server, char *arg);
bool bind_freq(server_t *server, char *arg);

const flag_binding_t FLAG_BINDING[] = {
    {.flag = 'p', .binding = &bind_port},
    {.flag = 'x', .binding = &bind_width},
    {.flag = 'y', .binding = &bind_height},
    {.flag = 'n', .binding = &bind_team},
    {.flag = 'c', .binding = &bind_clients_nb},
    {.flag = 'f', .binding = &bind_freq},
    {0}
};
