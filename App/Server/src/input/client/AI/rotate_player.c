/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** rotate_player
*/

#include "Server/cmd_ai_client.h"

void rotate_west(player_t *player)
{
    player->direction = WEST;
    print_msg(player->fd_client, "ok\n");
}

void rotate_east(player_t *player)
{
    player->direction = EAST;
    print_msg(player->fd_client, "ok\n");
}

void rotate_north(player_t *player)
{
    player->direction = NORTH;
    print_msg(player->fd_client, "ok\n");
}

void rotate_south(player_t *player)
{
    player->direction = SOUTH;
    print_msg(player->fd_client, "ok\n");
}
