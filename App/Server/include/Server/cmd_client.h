/*
** EPITECH PROJECT, 2024
** zappy_server
** File description:
** cmd_client
*/

#pragma once

typedef struct cmd_builtin_client_s {
    const char *command;
    void (*function)(const int fd, const char *arg);
} cmd_builtin_client_t;

void cmd_frequence(const int fd, const char *frequence);
void cmd_team_names(const int fd, const char *team_names);
void cmd_map_size(const int fd, const char *map_size);
void cmd_map_tile_content(const int fd, const char *tile_content);
