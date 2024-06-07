/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_tile_content
*/

#include "Server/cmd_gui_client.h"
#include "Server/tools.h"
#include <stdio.h>
#include <stdlib.h>

void cmd_tile_content(const int fd, char **cmd)
{
    int x = atoi(cmd[1]);
    int y = atoi(cmd[2]);

    if (x < 0 || y < 0) {
        print_msg(fd, "ko\n");
        return;
    }
    printf("bct %d %d\n", x, y);
    print_msg(fd, "content of tile\n");
}
