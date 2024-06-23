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
    void (*function)(player_t *player, game_t *game);
} cmd_ai_client_t;

void cmd_ai_client(player_t *player, game_t *game, char *cmd);
void rotate_west(player_t *player);
void rotate_east(player_t *player);
void rotate_north(player_t *player);
void rotate_south(player_t *player);
void cmd_forward(player_t *player, game_t *game);
void cmd_right(player_t *player, game_t *game);
void cmd_left(player_t *player, game_t *game);
void cmd_look(player_t *player, game_t *game);
void cmd_inventory(player_t *player, game_t *game);
void cmd_broadcast(player_t *player, game_t *game);
void cmd_connection_nbr(player_t *player, game_t *game);
void cmd_fork(player_t *player, game_t *game);
void cmd_eject(player_t *player, game_t *game);
void cmd_take(player_t *player, game_t *game);
void cmd_set(player_t *player, game_t *game);
void cmd_incantation(player_t *player, game_t *game);
void cmd_dead(player_t *player, game_t *game);

void connect_ai(
    game_t *game,
    data_t *client,
    int fd,
    char *team_name);
