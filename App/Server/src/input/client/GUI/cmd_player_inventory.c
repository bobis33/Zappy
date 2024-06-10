/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_player_inventory
*/

#include "Server/cmd_gui_client.h"
#include "Server/tools.h"

void cmd_player_inventory(const int fd, char **cmd, game_t *game)
{
    int player_id = atoi(cmd[1]);

    if (player_id < 0 || player_id >= game->max_clients) {
        print_msg(fd, "ko\n");
        return;
    }
    print_msg(fd, "pin ");
    print_msg(fd, cmd[1]);
    dprintf(fd, " %d %d %d %d %d %d %d %d %d\n", game->players[player_id].id,
        game->players[player_id].pos_x, game->players[player_id].pos_y,
        game->players[player_id].resources[FOOD].quantity,
        game->players[player_id].resources[LINEMATE].quantity,
        game->players[player_id].resources[DERAUMERE].quantity,
        game->players[player_id].resources[SIBUR].quantity,
        game->players[player_id].resources[MENDIANE].quantity,
        game->players[player_id].resources[PHIRAS].quantity,
        game->players[player_id].resources[THYSTAME].quantity);
}
