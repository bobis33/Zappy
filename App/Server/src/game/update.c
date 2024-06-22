/*
** EPITECH PROJECT, 2024
** Server
** File description:
** update
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>

#include "Server/Game/update.h"

static void update_eggs(game_t *game)
{
    for (int i = 0; i < game->map->width * game->map->height; i++) {
        if (game->map->tiles[i]->egg.id == -1)
            continue;
        if (get_ticks_elapsed(game->map->tiles[i]->egg.laid_time) >= 600) {
            game->map->tiles[i]->egg.id = -1;
        }
    }
}

static void update_map_resources(game_t *game)
{
    int ticks_elapsed = get_ticks_elapsed(game->map_resources_clock);

    if (ticks_elapsed >= 20) {
        distribute_resources(game);
        clock_gettime(CLOCK_MONOTONIC, &game->map_resources_clock->value);
    }
}

static void update_player_food(game_t *game, client_t *clients, int index)
{
    if ((get_ticks_elapsed(game->players[index]->clock) < 126))
        return;
    if (game->players[index]->resources[FOOD].quantity > 0) {
        game->players[index]->resources[FOOD].quantity--;
        game->players[index]->clock = game->clock;
        return;
    }
    for (int j = 0; j < MAX_CLIENTS; j++) {
        if (clients->clients[j].fd == ERROR)
            continue;
        dprintf(clients->clients[j].fd, "pdi %d\n", game->players[index]->id);
        clients->clients[j].fd = -1;
    }
}

void update_game(game_t *game, client_t *clients)
{
    for (int i = 0; game->players[i] != NULL; i++) {
        if (is_current_action_done(game->players[i])) {
            execute_player_action(game->players[i]);
        }
        update_player_food(game, clients, i);
    }
    update_map_resources(game);
}
