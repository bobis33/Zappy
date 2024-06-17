/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_look
*/

#include "Server/cmd_ai_client.h"

static void look_west(player_t *player, game_t *game)
{
    (void)game;
    print_msg(player->fd_client, "ok\n");
}

static void look_east(player_t *player, game_t *game)
{
    (void)game;
    print_msg(player->fd_client, "ok\n");
}

static void look_south(player_t *player, game_t *game)
{
    (void)game;
    print_msg(player->fd_client, "ok\n");
}

static void look_north(player_t *player, game_t *game)
{
    (void)game;
    print_msg(player->fd_client, "ok\n");
}

void cmd_look(player_t *player, game_t *game)
{
    switch (player->direction) {
        case NORTH:
            look_north(player, game);
            break;
        case SOUTH:
            look_south(player, game);
            break;
        case EAST:
            look_east(player, game);
            break;
        case WEST:
            look_west(player, game);
            break;
        default:
            print_msg(player->fd_client, "ko\n");
            break;
    }
}
