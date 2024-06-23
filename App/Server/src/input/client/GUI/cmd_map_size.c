/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_map_size
*/

#include "Server/cmd_gui_client.h"
#include "Server/tools.h"

void cmd_map_size(const int fd, char **cmd, game_t *game)
{
    char *x_len = malloc(sizeof(char) * 3);
    char *y_len = malloc(sizeof(char) * 3);

    (void)cmd;
    sprintf(x_len, "%d", game->map->height);
    sprintf(y_len, "%d", game->map->width);
    print_msg(fd, "msz ");
    print_msg(fd, x_len);
    print_msg(fd, " ");
    print_msg(fd, y_len);
    print_msg(fd, "\n");
    free(x_len);
    free(y_len);
}
