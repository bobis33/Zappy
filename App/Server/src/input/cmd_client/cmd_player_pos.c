/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_player_pos
*/

#include "Server/cmd_client.h"
#include "Server/tools.h"
#include <stdio.h>
#include <stdlib.h>

void cmd_player_pos(const int fd, char **cmd)
{
    int player_id = 0;
    char *player_id_str = cmd[1];

    player_id_str++;
    player_id = atoi(player_id_str);
    printf("player_id = %d\n", player_id);
    print_msg(fd, "player position\n");
}
