/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_incantation
*/

#include "Server/cmd_ai_client.h"

void cmd_incantation(const int fd, game_t *game)
{
    (void)game;
    print_msg(fd, "Elevation underway\n");
    print_msg(fd, "Current level: UN MILLION\n");
    print_msg(fd, "ko\n");
}
