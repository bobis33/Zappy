/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_ai_client
*/

#pragma once

#include "Server/client.h"

typedef struct cmd_ai_client_s {
    const char *command;
    void (*function)(const int fd);
} cmd_ai_client_t;

void cmd_ai_client(game_t *game, client_t *client, char *cmd, const int fd);
void cmd_forward(const int fd);
void cmd_right(const int fd);
void cmd_left(const int fd);
void cmd_look(const int fd);
void cmd_inventory(const int fd);
void cmd_broadcast(const int fd);
void cmd_connection_nbr(const int fd);
void cmd_fork(const int fd);
void cmd_eject(const int fd);
void cmd_take(const int fd);
void cmd_set(const int fd);
void cmd_incantation(const int fd);
void cmd_dead(const int fd);
