/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_map_tile_content
*/

#include <string.h>

#include "Server/cmd_gui_client.h"
#include "Server/tools.h"

static void display_tile_content(int fd, game_t *game, int width, int height)
{
    char *content = malloc(sizeof(char) * 10240);
    tile_t *tile = get_tile_by_pos(game->map, width, height);

    snprintf(content, 10240, "%d %d ",
        tile->pos->x, tile->pos->y);
    for (int i = 0; i < COUNT; i++) {
        snprintf(content + strlen(content), 10240, "%d",
            tile->resources[i]->quantity);
        if (i < COUNT - 1) {
            strcat(content, " ");
        }
    }
    strcat(content, "\n");
    printf("content: %s\n", content);
    print_msg(fd, content);
}

void cmd_map_tile_content(const int fd, char **cmd, game_t *game)
{
    (void)cmd;
    for (int height = 0; height < game->map->height; height++) {
        for (int width = 0; width < game->map->width; width++) {
            print_msg(fd, "bct ");
            display_tile_content(fd, game, width, height);
        }
    }
}
