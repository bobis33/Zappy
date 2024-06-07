/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_frequency_update
*/

#include <stdio.h>

#include "Server/cmd_gui_client.h"
#include "Server/tools.h"

void cmd_frequency_update(const int fd, char **cmd)
{
    int new_freq = atoi(cmd[1]);

    printf("new_freq = %d\n", new_freq);
    print_msg(fd, "frequency update\n");
}
