/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_forward
*/

#include "Server/cmd_ai_client.h"

static void move_upper(game_t *game, const int fd)
{
    (void)game;
    print_msg(fd, "ok\n");
}

static void move_lower(game_t *game, const int fd)
{
    (void)game;
    print_msg(fd, "ok\n");
}

static void move_right(game_t *game, const int fd)
{
    (void)game;
    print_msg(fd, "ok\n");
}

static void move_left(game_t *game, const int fd)
{
    (void)game;
    print_msg(fd, "ok\n");
}

void cmd_forward(const int fd, game_t *game)
{
    (void)game;
    (void)fd;
}
