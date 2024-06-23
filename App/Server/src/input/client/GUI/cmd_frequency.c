/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_frequency
*/

#include "Server/cmd_gui_client.h"
#include "Server/tools.h"

void cmd_frequency(const int fd, char **cmd, game_t *game)
{
    char *content = malloc(sizeof(char) * 4);

    (void)cmd;
    print_msg(fd, "sgt ");
    sprintf(content, "%d", game->clock->freq);
    print_msg(fd, content);
    print_msg(fd, "\n");
}
