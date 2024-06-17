/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_incantation
*/

#include "Server/cmd_ai_client.h"

void cmd_incantation(player_t *player, game_t *game)
{
    (void)game;
    print_msg(player->fd_client, "Elevation underway\n");
    print_msg(player->fd_client, "Current level: UN MILLION\n");
    print_msg(player->fd_client, "ko\n");
}
