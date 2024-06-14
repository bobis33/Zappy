/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_eject
*/

#include "Server/cmd_ai_client.h"

void cmd_eject(const int fd, game_t *game)
{
    (void)game;
    print_msg(fd, "ok/ko\n");
}
