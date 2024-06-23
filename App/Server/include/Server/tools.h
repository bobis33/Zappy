/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** tools.h
*/

#pragma once

#include <stdbool.h>

#include "Server/Game/map.h"

void free_array(char **array);
bool print_msg(int fd, const char *msg);
bool is_perror(int is_error, const char *msg);
tile_t *get_tile_by_pos(map_t *game, int x, int y);
