/*
** EPITECH PROJECT, 2024
** Server
** File description:
** egg
*/

#pragma once

#include "Server/Game/position.h"
#include "Server/Game/clock.h"

typedef enum egg_state_e {
    EGG_HATCHING,
    EGG_HATCHED
} egg_state_t;

typedef struct egg_s {
    int id;
    int player_id;
    char *team_name;
    position_t pos;
    server_clock_t *laid_time;
} egg_t;

egg_t create_egg(
    int id,
    server_clock_t *laid_time,
    char *team_name,
    position_t pos);
