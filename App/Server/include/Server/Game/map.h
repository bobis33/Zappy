/*
** EPITECH PROJECT, 2024
** Server
** File description:
** map
*/

#pragma once

#include <stdbool.h>

#include "Server/Game/game.h"

typedef struct tile_s {
    int pos_x;
    int pos_y;
    resource_t resources[COUNT];
} tile_t;

typedef struct map_s {
    int width;
    int height;
    tile_t **tiles;
} map_t;
