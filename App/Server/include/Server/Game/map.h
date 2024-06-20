/*
** EPITECH PROJECT, 2024
** Server
** File description:
** map
*/

#pragma once

#include <stdbool.h>

#include "Server/Game/resource.h"
#include "Server/Game/egg.h"
#include "Server/Game/position.h"

typedef struct tile_s {
    position_t pos;
    resource_t resources[COUNT];
    egg_t egg;
} tile_t;

typedef struct map_s {
    int width;
    int height;
    tile_t **tiles;
} map_t;
