/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_player_lvl
*/

#include "Server/cmd_gui_client.h"
#include "Server/tools.h"

void cmd_player_lvl(const int fd, char **cmd, game_t *game)
{
    int player_id = atoi(cmd[1]);

    if (player_id < 0 || player_id >= game->max_clients) {
        print_msg(fd, "ko\n");
        return;
    }
    print_msg(fd, "plv ");
    print_msg(fd, cmd[1]);
    dprintf(fd, " %d\n", game->players[player_id].level);
}
