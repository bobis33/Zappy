/*
** EPITECH PROJECT, 2024
** zappy_server
** File description:
** cmd_client
*/

#pragma once

#include "Server/client.h"

typedef struct cmd_builtin_client_s {
    const char *command;
    void (*function)(const int fd, char **arg);
} cmd_builtin_client_t;

void cmd_gui_client(game_t *game, client_t *client, char *cmd, int fd);
void cmd_map_size(int fd, char **cmd);
void cmd_tile_content(int fd, char **cmd);
void cmd_map_tile_content(int fd, char **cmd);
void cmd_team_names(int fd, char **cmd);
void cmd_player_pos(int fd, char **cmd);
void cmd_player_lvl(int fd, char **cmd);
void cmd_player_inventory(int fd, char **cmd);
void cmd_frequency(int fd, char **cmd);
void cmd_frequency_update(int fd, char **cmd);
