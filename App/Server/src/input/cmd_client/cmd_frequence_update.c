/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_frequence_update
*/

#include "Server/cmd_client.h"
#include "Server/tools.h"
#include <stdio.h>
#include <stdlib.h>

void cmd_frequence_update(const int fd, char **cmd)
{
    int new_freq = 0;

    new_freq = atoi(cmd[1]);
    printf("new_freq = %d\n", new_freq);
    print_msg(fd, "frequence update\n");
}
