/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** rotate_player
*/

#include "Server/cmd_ai_client.h"

void rotate_west(const int fd, game_t *game)
{
    game->players[fd].direction = WEST;
    print_msg(fd, "ok\n");
}

void rotate_east(const int fd, game_t *game)
{
    game->players[fd].direction = EAST;
    print_msg(fd, "ok\n");
}

void rotate_north(const int fd, game_t *game)
{
    game->players[fd].direction = NORTH;
    print_msg(fd, "ok\n");
}

void rotate_south(const int fd, game_t *game)
{
    game->players[fd].direction = SOUTH;
    print_msg(fd, "ok\n");
}
