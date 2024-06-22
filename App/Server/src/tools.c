/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** tools
*/

#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Server/Game/map.h"

tile_t *get_tile_by_pos(map_t *map, int x, int y)
{
    for (int i = 0; i < map->width * map->height; i++) {
        if (map->tiles[i]->pos->x == x
            && map->tiles[i]->pos->y == y) {
            return map->tiles[i];
        }
    }
    return NULL;
}

bool *stop_signal_catched(void)
{
    static bool globalStop = false;

    return &globalStop;
}

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}

bool is_perror(const int is_perror, const char *msg)
{
    if (is_perror == -1) {
        perror(msg);
        return true;
    }
    return false;
}

bool print_msg(const int fd, const char *msg)
{
    return write(fd, msg, strlen(msg)) != -1;
}
