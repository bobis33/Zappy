/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_frequency
*/

#include "Server/cmd_gui_client.h"
#include "Server/tools.h"

void cmd_frequency(const int fd, char **cmd)
{
    (void)cmd;
    print_msg(fd, "actual frequency\n");
}
