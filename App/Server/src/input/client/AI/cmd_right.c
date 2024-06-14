/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_right
*/

#include "Server/cmd_ai_client.h"

void cmd_right(const int fd, game_t *game)
{
    switch (game->players[fd].direction) {
        case NORTH:
            rotate_east(fd, game);
            break;
        case SOUTH:
            rotate_west(fd, game);
            break;
        case EAST:
            rotate_south(fd, game);
            break;
        case WEST:
            rotate_north(fd, game);
            break;
        default:
            print_msg(fd, "ko\n");
            return;
    }
}
