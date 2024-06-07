/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_tile_content
*/

#include <stdio.h>

#include "Server/cmd_gui_client.h"
#include "Server/tools.h"

void cmd_tile_content(const int fd, char **cmd)
{
    int width = atoi(cmd[1]);
    int height = atoi(cmd[2]);

    if (width < 0 || height < 0) {
        print_msg(fd, "ko\n");
        return;
    }
    printf("bct %d %d\n", width, height);
    print_msg(fd, "content of tile\n");
}
