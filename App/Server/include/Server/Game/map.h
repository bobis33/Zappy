/*
** EPITECH PROJECT, 2024
** Server
** File description:
** map
*/

#pragma once

#include <stdbool.h>

#include "Server/Game/tile.h"

typedef struct map_s {
    int width;
    int height;
    tile_t **tiles;
} map_t;
