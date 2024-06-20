/*
** EPITECH PROJECT, 2024
** Server
** File description:
** egg
*/

#pragma once

#include "Server/Game/position.h"

typedef struct egg_s {
    int id;
    int player_id;
    int laid_time;
    char *team_name;
    position_t pos;
} egg_t;

egg_t create_egg(
    int id,
    int laid_time,
    char *team_name,
    position_t pos);
