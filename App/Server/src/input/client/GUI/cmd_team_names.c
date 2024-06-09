/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_team_names
*/

#include "Server/cmd_gui_client.h"
#include "Server/tools.h"

void cmd_team_names(const int fd, char **cmd, game_t *game)
{
    (void)cmd;
    for (int i = 0; i < game->nb_teams; i++) {
        print_msg(fd, "tna ");
        print_msg(fd, game->team_names[i]);
        print_msg(fd, "\n");
    }
}
