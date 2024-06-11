/*
** EPITECH PROJECT, 2024
** zappy_server
** File description:
** game
*/

#include "Server/Game/game.h"

void free_game_resources(game_t *game)
{
    free(game->clock);
    if (game->map != NULL && game->map->tiles != NULL) {
        for (int i = 0; i < game->map->width; i++) {
            free(game->map->tiles[i]);
        }
        free(game->map->tiles);
    }
    free(game->map);
    if (game->players == NULL) {
        return;
    }
    for (int i = 0; i < game->max_clients; i++) {
        if (game->players[i] != NULL) {
            free(game->players[i]);
        }
    }
    free(game->players);
    free(game);
}

static bool init_player(game_t *game, map_t **map_ptr)
{
    *map_ptr = malloc(sizeof(player_t *) *
        ((unsigned long)game->max_clients *
        (unsigned long)game->nb_teams));
    if (!*map_ptr) {
        return false;
    }
    game->map = *map_ptr;
    if (!game->players) {
        return false;
    }
    for (int i = 0; i < game->max_clients; i++) {
        game->players[i] = NULL;
    }
    return true;
}

static void fill_game(game_t *game, arguments_t *args)
{
    game->clock = malloc(sizeof(server_clock_t));
    game->clock->freq = args->freq;
    clock_gettime(CLOCK_MONOTONIC, &game->clock->value);
    game->max_clients = args->clients_nb;
    game->nb_teams = args->nb_teams;
    game->team_names = args->team_names;
}

bool start_game(arguments_t *args, game_t **game_ptr)
{
    game_t *game = NULL;

    *game_ptr = malloc(sizeof(game_t));
    if (!*game_ptr) {
        return false;
    }
    game = *game_ptr;
    fill_game(game, args);
    if (!init_player(game, &game->map) ||
        !init_map(game, args->width, args->height)) {
        free_game_resources(game);
        return false;
    }
    return true;
}
