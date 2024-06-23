/*
** EPITECH PROJECT, 2024
** zappy_server
** File description:
** cmd_client
*/

#pragma once

#include <stdio.h>
#include "Server/client.h"

typedef struct cmd_builtin_client_s {
    const char *command;
    void (*function)(const int fd, char **arg, game_t *game);
} cmd_builtin_client_t;

void cmd_gui_client(game_t *game, char *cmd, int fd);
void cmd_map_size(int fd, char **cmd, game_t *game);
void cmd_tile_content(int fd, char **cmd, game_t *game);
void cmd_map_tile_content(int fd, char **cmd, game_t *game);
void cmd_team_names(int fd, char **cmd, game_t *game);
void cmd_player_pos(int fd, char **cmd, game_t *game);
void cmd_player_lvl(int fd, char **cmd, game_t *game);
void cmd_player_inventory(int fd, char **cmd, game_t *game);
void cmd_frequency(int fd, char **cmd, game_t *game);
void cmd_frequency_update(int fd, char **cmd, game_t *game);

void connect_gui(game_t *game, data_t *client, int fd);
