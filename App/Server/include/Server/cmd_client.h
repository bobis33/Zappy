/*
** EPITECH PROJECT, 2024
** zappy_server
** File description:
** cmd_client
*/

#pragma once

typedef struct cmd_builtin_client_s {
    const char *command;
    void (*function)(void);
} cmd_builtin_client_t;
