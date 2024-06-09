/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_tile_content
*/

#include "Server/cmd_gui_client.h"
#include "Server/tools.h"

void cmd_tile_content(const int fd, char **cmd, game_t *game)
{
    int width = atoi(cmd[1]);
    int height = atoi(cmd[2]);
    char *content = malloc(sizeof(char) * 21);

    if (width > game->map->width || height > game->map->height || width < 0
        || height < 0) {
        print_msg(fd, "ko\n");
        return;
    }
    print_msg(fd, "bct ");
    for (int i = 0; i < COUNT; i++) {
        sprintf(content, "%d",
            game->map->tiles[height][width].resources[i].quantity);
        print_msg(fd, content);
        if (i < COUNT - 1)
            print_msg(fd, " ");
    }
    print_msg(fd, "\n");
}
