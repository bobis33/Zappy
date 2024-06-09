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
    int player_id = 0;
    char *player_id_str = cmd[1];

    (void)game;
    player_id_str++;
    player_id = atoi(player_id_str);
    printf("player_id = %d\n", player_id);
    print_msg(fd, "player inventory\n");
}
