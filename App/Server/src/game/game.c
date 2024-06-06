/*
** EPITECH PROJECT, 2024
** zappy_server
** File description:
** game
*/

#include <time.h>

#include "Server/Game/game.h"

void free_game_resources(game_t *game)
{
    if (!game) {
        return;
    }
    if (!game->map) {
        free(game);
        return;
    }
    if (game->map->tiles) {
        for (int i = 0; i < game->map->width; i++) {
            free(game->map->tiles[i]);
        }
        free(game->map->tiles);
    }
    free(game->map);
    free(game);
}

static bool init_map(game_t *game, const int width, const int height)
{
    game->map = malloc(sizeof(map_t));
    if (!game->map) {
        return false;
    }
    game->map->width = width;
    game->map->height = height;
    game->map->tiles = NULL;
    return true;
}

static bool init_tiles(game_t *game)
{
    game->map->tiles =
        malloc(sizeof(tile_t *) * (unsigned long)game->map->width);
    if (!game->map->tiles) {
        return false;
    }
    for (int i = 0; i < game->map->width; i++) {
        game->map->tiles[i] =
            malloc(sizeof(tile_t) * (unsigned long)game->map->height);
        if (!game->map->tiles[i]) {
            free(game->map->tiles);
            return false;
        }
    }
    return true;
}

static void init_tile_resources(game_t *game)
{
    for (int i = 0; i < game->map->width; i++) {
        for (int j = 0; j < game->map->height; j++) {
            game->map->tiles[i][j].pos_x = i;
            game->map->tiles[i][j].pos_y = j;
            game->map->tiles[i][j].resources[FOOD].quantity = 0;
            game->map->tiles[i][j].resources[LINEMATE].quantity = 0;
            game->map->tiles[i][j].resources[DERAUMERE].quantity = 0;
            game->map->tiles[i][j].resources[SIBUR].quantity = 0;
            game->map->tiles[i][j].resources[MENDIANE].quantity = 0;
            game->map->tiles[i][j].resources[PHIRAS].quantity = 0;
            game->map->tiles[i][j].resources[THYSTAME].quantity = 0;
        }
    }
}

bool init_game(arguments_t *args, game_t **game_ptr)
{
    game_t *game = NULL;

    *game_ptr = malloc(sizeof(game_t));
    if (!*game_ptr) {
        return false;
    }
    game = *game_ptr;
    game->clock = malloc(sizeof(server_clock_t));
    game->clock->freq = args->freq;
    clock_gettime(CLOCK_MONOTONIC, &game->clock->value);
    game->max_clients = args->clients_nb;
    game->nb_teams = args->nb_teams;
    game->team_names = args->team_names;
    if (!init_map(game, args->width, args->height) || !init_tiles(game)) {
        free_game_resources(game);
        *game_ptr = NULL;
        return false;
    }
    init_tile_resources(game);
    return true;
}
