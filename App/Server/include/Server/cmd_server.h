/*
** EPITECH PROJECT, 2024
** zappy_server
** File description:
** cmd_server
*/

#pragma once

#include "Server/server.h"

typedef struct cmd_builtin_server_s {
    const char *command;
    server_status_t (*function)(void);
} cmd_builtin_server_t;

server_status_t cmd_quit(void);
