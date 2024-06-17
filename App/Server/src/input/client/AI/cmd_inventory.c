/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_inventory
*/

#include "Server/cmd_ai_client.h"

void cmd_inventory(player_t *player, game_t *game)
{
    (void)game;
    print_msg(player->fd_client, "[linemate n, sibur n, ...]\n");
}
