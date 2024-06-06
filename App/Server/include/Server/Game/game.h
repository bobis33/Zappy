/*
** EPITECH PROJECT, 2024
** zappy_server
** File description:
** game
*/

#pragma once

#include <stdbool.h>

#include "Server/arguments.h"
#include "Server/Game/clock.h"

typedef enum direction_e {
    NORTH,
    EAST,
    SOUTH,
    WEST
} direction_t;

typedef enum resource_type_e {
    FOOD = 0,
    LINEMATE = 1,
    DERAUMERE = 2,
    SIBUR = 3,
    MENDIANE = 4,
    PHIRAS = 5,
    THYSTAME = 6,
    COUNT = 7
} resource_type_t;

typedef struct resource_s {
    int quantity;
    double density;
    resource_type_t type;
} resource_t;

typedef struct player_s {
    int pos_x;
    int pos_y;
    direction_t direction;
    resource_t resources[COUNT];
} player_t;

typedef struct tile_s {
    int pos_x;
    int pos_y;
    resource_t resources[COUNT];
} tile_t;

typedef struct map_s {
    int width;
    int height;
    tile_t **tiles;
} map_t;

typedef struct game_s {
    int max_clients;
    int nb_teams;
    map_t *map;
    server_clock_t *clock;
    char **team_names;
} game_t;

bool init_game(arguments_t *args, game_t **game);
void free_game_resources(game_t *game);
