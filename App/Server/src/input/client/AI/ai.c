/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** ai_cmd
*/

#include <string.h>

#include "Server/cmd_ai_client.h"

static const cmd_ai_client_t cmd_ai[] = {
    {"Forward\n", cmd_forward},
    {"Right\n", cmd_right},
    {"Left\n", cmd_left},
    {"Look\n", cmd_look},
    {"Inventory\n", cmd_inventory},
    {"Broadcast\n", cmd_broadcast},
    {"Connect_nbr\n", cmd_connection_nbr},
    {"Fork\n", cmd_fork},
    {"Eject\n", cmd_eject},
    {"Take\n", cmd_take},
    {"Set\n", cmd_set},
    {"Incantation\n", cmd_incantation},
    {NULL, NULL}
};

void cmd_ai_client(player_t *player, game_t *game, char *cmd)
{
    for (int i = 0; cmd_ai[i].command; i++) {
        if (strcmp(cmd, cmd_ai[i].command) == 0) {
            cmd_ai[i].function(player, game);
            return;
        }
    }
    print_msg(player->fd_client, "ko\n");
}
