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

void cmd_ai_client(game_t *game, client_t *client, char *cmd, int fd);
void cmd_forward(int fd);
void cmd_right(int fd);
void cmd_left(int fd);
void cmd_look(int fd);
void cmd_inventory(int fd);
void cmd_broadcast(int fd);
void cmd_connection_nbr(int fd);
void cmd_fork(int fd);
void cmd_eject(int fd);
void cmd_take(int fd);
void cmd_set(int fd);
void cmd_incantation(int fd);
void cmd_dead(int fd);
