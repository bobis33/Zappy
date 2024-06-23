/*
** EPITECH PROJECT, 2024
** Server
** File description:
** map
*/

#include <stdlib.h>

#include "Server/Game/game.h"

static void distribute_egg(game_t *game, int index)
{
    int x = 0;
    int y = 0;

    for (int j = 0; j < game->max_clients; j++) {
        x = rand() % game->map->width;
        y = rand() % game->map->height;
        if (game->map->tiles[x][y].egg.id != -1) {
            j--;
            continue;
        }
        game->map->tiles[x][y].egg =
            create_egg(j,
                game->clock,
                game->team_names[index],
                (position_t){x, y});
    }
}

void distribute_resources(game_t *game)
{
    int x = 0;
    int total_resources = 0;

    for (int i = 0; i < COUNT; i++) {
        total_resources = (int)(game->map->width *
                                game->map->height *
                                game->map->tiles[0]->resources[i]->density);
        while (total_resources > 0) {
            srand(rand());
            x = rand() % (game->map->width * game->map->height);
            game->map->tiles[x]->resources[i]->quantity++;
            total_resources--;
        }
    }
}

static void fill_tiles(game_t *game)
{
    for (int i = 0; i < game->map->width * game->map->height; i++) {
        game->map->tiles[i]->egg = (egg_t){-1, -1, NULL,
            (position_t){0, 0}, (server_clock_t *)NULL};
        game->map->tiles[i]->pos = malloc(sizeof(position_t));
        game->map->tiles[i]->pos->x = i % game->map->width;
        game->map->tiles[i]->pos->y = i / game->map->width;
        for (int j = 0; j < COUNT; j++) {
            game->map->tiles[i]->resources[j] = malloc(sizeof(resource_t));
            game->map->tiles[i]->resources[j]->quantity = 0;
            game->map->tiles[i]->resources[j]->type = j;
        }
        game->map->tiles[i]->resources[FOOD]->density = 0.5;
        game->map->tiles[i]->resources[LINEMATE]->density = 0.3;
        game->map->tiles[i]->resources[DERAUMERE]->density = 0.15;
        game->map->tiles[i]->resources[SIBUR]->density = 0.1;
        game->map->tiles[i]->resources[MENDIANE]->density = 0.1;
        game->map->tiles[i]->resources[PHIRAS]->density = 0.08;
        game->map->tiles[i]->resources[THYSTAME]->density = 0.05;
    }
}

bool init_tiles(game_t *game)
{
    game->map->tiles = malloc(sizeof(tile_t *) *
        (unsigned long)(game->map->width * game->map->height));
    if (!game->map->tiles) {
        return false;
    }
    for (int i = 0; i < game->map->width * game->map->height; i++) {
        game->map->tiles[i] = malloc(sizeof(tile_t));
        if (!game->map->tiles[i]) {
            return false;
        }
    }
    fill_tiles(game);
    distribute_resources(game);
    for (int i = 0; i < game->nb_teams; i++) {
        distribute_egg(game, i);
    }
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
