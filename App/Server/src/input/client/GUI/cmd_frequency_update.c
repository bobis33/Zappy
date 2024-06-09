/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_frequency_update
*/

#include "Server/cmd_gui_client.h"
#include "Server/tools.h"

void cmd_frequency_update(const int fd, char **cmd, game_t *game)
{
    int new_freq = atoi(cmd[1]);

    if (new_freq < 0 || new_freq > 1000) {
        print_msg(fd, "ko\n");
        return;
    }
    game->clock->freq = new_freq;
    print_msg(fd, "sst ");
    print_msg(fd, cmd[1]);
    print_msg(fd, "\n");
}
