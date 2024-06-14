/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_forward
*/

#include "Server/cmd_ai_client.h"

static void move_upper(game_t *game, const int fd)
{
    if (game->players[fd].pos_y == 0)
        game->players[fd].pos_y = game->map->height - 1;
    else
        game->players[fd].pos_y--;
    print_msg(fd, "ok\n");
}

static void move_lower(game_t *game, const int fd)
{
    if (game->players[fd].pos_y == game->map->height - 1)
        game->players[fd].pos_y = 0;
    else
        game->players[fd].pos_y++;
    print_msg(fd, "ok\n");
}

static void move_right(game_t *game, const int fd)
{
    if (game->players[fd].pos_x == game->map->width - 1)
        game->players[fd].pos_x = 0;
    else
        game->players[fd].pos_x++;
    print_msg(fd, "ok\n");
}

static void move_left(game_t *game, const int fd)
{
    if (game->players[fd].pos_x == 0)
        game->players[fd].pos_x = game->map->width - 1;
    else
        game->players[fd].pos_x--;
    print_msg(fd, "ok\n");
}

void cmd_forward(const int fd, game_t *game)
{
    switch (game->players[fd].direction) {
        case NORTH:
            move_upper(game, fd);
            break;
        case SOUTH:
            move_lower(game, fd);
            break;
        case EAST:
            move_right(game, fd);
            break;
        case WEST:
            move_left(game, fd);
            break;
        default:
            print_msg(fd, "ko\n");
            return;
    }
}
