/*
** EPITECH PROJECT, 2024
** Server
** File description:
** map
*/

#include "Server/Game/game.h"

static void distribute_resources(game_t *game)
{
    int x = 0;
    int y = 0;
    int total_resources = 0;

    for (int i = 0; i < COUNT; i++) {
        total_resources = (int)(game->map->width *
                                game->map->height *
                                game->map->tiles[0][0].resources[i].density);
        while (total_resources > 0) {
            x = rand() % game->map->width;
            y = rand() % game->map->height;
            game->map->tiles[x][y].resources[i].quantity++;
            total_resources--;
        }
    }
}

static void fill_tiles(game_t *game)
{
    for (int i = 0; i < game->map->width; i++) {
        for (int j = 0; j < game->map->height; j++) {
            game->map->tiles[i][j].pos_x = i;
            game->map->tiles[i][j].pos_y = j;
            game->map->tiles[i][j].resources[FOOD].quantity = 0;
            game->map->tiles[i][j].resources[FOOD].density = 0.5;
            game->map->tiles[i][j].resources[LINEMATE].quantity = 0;
            game->map->tiles[i][j].resources[LINEMATE].density = 0.3;
            game->map->tiles[i][j].resources[DERAUMERE].quantity = 0;
            game->map->tiles[i][j].resources[DERAUMERE].density = 0.15;
            game->map->tiles[i][j].resources[SIBUR].quantity = 0;
            game->map->tiles[i][j].resources[SIBUR].density = 0.1;
            game->map->tiles[i][j].resources[MENDIANE].quantity = 0;
            game->map->tiles[i][j].resources[MENDIANE].density = 0.1;
            game->map->tiles[i][j].resources[PHIRAS].quantity = 0;
            game->map->tiles[i][j].resources[PHIRAS].density = 0.08;
            game->map->tiles[i][j].resources[THYSTAME].quantity = 0;
            game->map->tiles[i][j].resources[THYSTAME].density = 0.05;
        }
    }
}

bool init_tiles(game_t *game)
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
    fill_tiles(game);
    distribute_resources(game);
    return true;
}

bool init_map(game_t *game, const int width, const int height)
{
    game->map = malloc(sizeof(map_t));
    if (!game->map) {
        return false;
    }
    game->map->width = width;
    game->map->height = height;
    game->map->tiles = NULL;
    init_tiles(game);
    return true;
}
