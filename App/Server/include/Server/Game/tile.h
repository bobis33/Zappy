/*
** EPITECH PROJECT, 2024
** Server
** File description:
** tile
*/

#pragma once

#include "Server/Game/position.h"
#include "Server/Game/resource.h"
#include "Server/Game/egg.h"

typedef struct tile_s {
    position_t *pos;
    resource_t *resources[COUNT];
    egg_t egg;
} tile_t;
