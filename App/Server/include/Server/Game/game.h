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
#include "Server/Game/resource.h"
#include "Server/Game/map.h"
#include "Server/Game/player.h"

typedef struct game_s {
    int max_clients;
    int nb_teams;
    map_t *map;
    server_clock_t *clock;
    server_clock_t *map_resources_clock;
    char **team_names;
    player_t **players;
} game_t;

bool start_game(arguments_t *args, game_t **game);
bool init_map(game_t *game, const int width, const int height);
void free_game_resources(game_t *game);
void add_resource(map_t *map, resource_t resource);
void distribute_resources(game_t *game);
