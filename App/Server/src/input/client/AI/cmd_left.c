/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_left
*/

#include "Server/cmd_ai_client.h"

void cmd_left(player_t *player, game_t *game)
{
    (void)game;
    switch (player->direction) {
        case NORTH:
            rotate_west(player);
            break;
        case SOUTH:
            rotate_east(player);
            break;
        case EAST:
            rotate_north(player);
            break;
        case WEST:
            rotate_south(player);
            break;
        default:
            add_action_to_player(player, ACTION, "ko\n", 7);
            return;
    }
}
