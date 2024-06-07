/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_team_names
*/

#include "Server/cmd_client.h"
#include "Server/tools.h"

void cmd_team_names(const int fd, char **cmd)
{
    (void)cmd;
    print_msg(fd, "team names\n");
}
