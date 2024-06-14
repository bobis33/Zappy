/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_ai_client
*/

#pragma once

#include <stdio.h>

#include "Server/client.h"
#include "Server/tools.h"

typedef struct cmd_ai_client_s {
    const char *command;
    void (*function)(const int fd, game_t *game);
} cmd_ai_client_t;

void cmd_ai_client(game_t *game, client_t *client, char *cmd, int fd);
void rotate_west(const int fd, game_t *game);
void rotate_east(const int fd, game_t *game);
void rotate_north(const int fd, game_t *game);
void rotate_south(const int fd, game_t *game);
void cmd_forward(int fd, game_t *game);
void cmd_right(int fd, game_t *game);
void cmd_left(int fd, game_t *game);
void cmd_look(int fd, game_t *game);
void cmd_inventory(int fd, game_t *game);
void cmd_broadcast(int fd, game_t *game);
void cmd_connection_nbr(int fd, game_t *game);
void cmd_fork(int fd, game_t *game);
void cmd_eject(int fd, game_t *game);
void cmd_take(int fd, game_t *game);
void cmd_set(int fd, game_t *game);
void cmd_incantation(int fd, game_t *game);
void cmd_dead(int fd, game_t *game);
