/*
** EPITECH PROJECT, 2024
** Server
** File description:
** connect
*/

#include "Server/cmd_gui_client.h"
#include "Server/cmd_ai_client.h"
#include "Server/tools.h"

static void display_info(int fd, player_t *player)
{
    print_msg(fd, "pnw ");
    dprintf(fd, "#%d %d %d %d %d %s\n", player->id,
            player->position.x, player->position.y,
            player->direction, player->level,
            player->team_name);
    print_msg(fd, "pin ");
    dprintf(fd, "#%d %d %d %d %d %d %d %d %d %d\n", player->id,
            player->position.x, player->position.y,
            player->resources[FOOD].quantity,
            player->resources[LINEMATE].quantity,
            player->resources[DERAUMERE].quantity,
            player->resources[SIBUR].quantity,
            player->resources[MENDIANE].quantity,
            player->resources[PHIRAS].quantity,
            player->resources[THYSTAME].quantity);
}

void connect_ai(
    game_t *game,
    data_t *client,
    const int fd,
    char *team_name)
{
    client->identity = AI;
    add_player(create_player(team_name, game,
        (position_t){0, 0}, fd), game);
    dprintf(fd, "%d %d %d\n",
        game->max_clients - 1,
        game->map->width,
        game->map->height);
}

void connect_gui(game_t *game, data_t *client, const int fd)
{
    client->identity = GRAPHIC;
    cmd_map_size(fd, NULL, game);
    cmd_map_tile_content(fd, NULL, game);
    cmd_team_names(fd, NULL, game);
    for (int i = 0; game->players[i] != NULL; i++) {
        display_info(fd, game->players[i]);
    }
    cmd_frequency(fd, NULL, game);
}
