/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_connection_nbr
*/

#include "Server/cmd_ai_client.h"

void cmd_connection_nbr(player_t *player, game_t *game)
{
    (void)game;
    dprintf(player->fd_client, "%d\n", player->id);
}
