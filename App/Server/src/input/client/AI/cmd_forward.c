/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_forward
*/

#include "Server/cmd_ai_client.h"

static void move_upper(game_t *game, player_t *player)
{
    if (player->position.y == 0) {
        player->position.y = game->map->height - 1;
        print_msg(player->fd_client, "ok\n");
        return;
    }
    player->position.y--;
    print_msg(player->fd_client, "ok\n");
}

static void move_lower(game_t *game, player_t *player)
{
    if (player->position.y == game->map->height - 1) {
        player->position.y = 0;
        print_msg(player->fd_client, "ok\n");
        return;
    }
    player->position.y++;
    print_msg(player->fd_client, "ok\n");
}

static void move_right(game_t *game, player_t *player)
{
    if (player->position.x == game->map->width - 1){
        player->position.x = 0;
        print_msg(player->fd_client, "ok\n");
        return;
    }
    player->position.x++;
    print_msg(player->fd_client, "ok\n");
}

static void move_left(game_t *game, player_t *player)
{
    if (player->position.x == 0) {
        player->position.x = game->map->width - 1;
        print_msg(player->fd_client, "ok\n");
        return;
    }
    player->position.x--;
    print_msg(player->fd_client, "ok\n");
}

void cmd_forward(player_t *player, game_t *game)
{
    switch (player->direction) {
        case NORTH:
            move_upper(game, player);
            break;
        case SOUTH:
            move_lower(game, player);
            break;
        case EAST:
            move_right(game, player);
            break;
        case WEST:
            move_left(game, player);
            break;
        default:
            print_msg(player->fd_client, "ko\n");
            return;
    }
}
