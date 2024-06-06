/*
** EPITECH PROJECT, 2024
** zappy_server
** File description:
** cmd_client
*/

#include "Server/cmd_client.h"
#include "Server/tools.h"
#include "Server/arguments.h"

// char *cmd_parse = // del 4 char of freq
void cmd_frequence(const int fd, const char *frequence)
{
    print_msg(1, "sgt ");
    print_msg(1, frequence);
    print_msg(1, "\n");
}

void cmd_team_names(const int fd, const char *team_names)
{
    print_msg(1, "tna ");
    print_msg(1, team_names);
    print_msg(1, "\n");
}

void cmd_map_size(const int fd, const char *map_size)
{
    print_msg(1, "msz ");
    print_msg(1, map_size);
    print_msg(1, "\n");
}

void cmd_map_tile_content(const int fd, const char *tile_content)
{
    print_msg(1, "mct ");
    print_msg(1, tile_content);
    print_msg(1, "\n");
}
