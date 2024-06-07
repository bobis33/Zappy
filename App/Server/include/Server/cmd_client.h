/*
** EPITECH PROJECT, 2024
** zappy_server
** File description:
** cmd_client
*/

#pragma once

typedef struct cmd_builtin_client_s {
    const char *command;
    void (*function)(const int fd, char **arg);
} cmd_builtin_client_t;

void cmd_map_size(const int fd, char **cmd);
void cmd_tile_content(const int fd, char **cmd);
void cmd_map_tile_content(const int fd, char **cmd);
void cmd_team_names(const int fd, char **cmd);
void cmd_player_pos(const int fd, char **cmd);
void cmd_player_lvl(const int fd, char **cmd);
void cmd_player_inventory(const int fd, char **cmd);
void cmd_frequence(const int fd, char **cmd);
void cmd_frequence_update(const int fd, char **cmd);
