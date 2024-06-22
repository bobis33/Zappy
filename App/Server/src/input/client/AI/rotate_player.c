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
    add_action_to_player(player, ACTION, "ok\n", 7);
}

void rotate_east(player_t *player)
{
    player->direction = EAST;
    add_action_to_player(player, ACTION, "ok\n", 7);
}

void rotate_north(player_t *player)
{
    player->direction = NORTH;
    add_action_to_player(player, ACTION, "ok\n", 7);
}

void rotate_south(player_t *player)
{
    player->direction = SOUTH;
    add_action_to_player(player, ACTION, "ok\n", 7);
}
