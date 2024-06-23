/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_right
*/

#include "Server/cmd_ai_client.h"

void cmd_right(player_t *player, game_t *game)
{
    (void)game;
    switch (player->direction) {
        case NORTH:
            rotate_east(player);
            break;
        case SOUTH:
            rotate_west(player);
            break;
        case EAST:
            rotate_south(player);
            break;
        case WEST:
            rotate_north(player);
            break;
        default:
            print_msg(player->fd_client, "ko\n");
            return;
    }
}
