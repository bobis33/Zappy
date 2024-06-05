/*
** EPITECH PROJECT, 2024
** zappy_server
** File description:
** game
*/

#pragma once

typedef struct resources_s {
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
} resources_t;

typedef struct player_s {
    int pos_x;
    int pos_y;
    resources_t resources;
} player_t;

typedef struct tile_s {
    int pos_x;
    int pos_y;
    resources_t resources;
} tile_t;

typedef struct map_s {
    int width;
    int height;
    tile_t **tiles;
} map_t;

typedef struct game_s {
    int freq;
    int max_clients;
    int nb_teams;
    map_t *map;
    char **team_names;
} game_t;
