/*
** EPITECH PROJECT, 2024
** Server
** File description:
** player
*/

#pragma once

typedef enum orientation_e {
    NORTH,
    EAST,
    SOUTH,
    WEST
} orientation_t;

typedef struct player_s {
    int pos_x;
    int pos_y;
    int life_units; // 126 * 10 at start (in frequency, or 10 life units)
    orientation_t direction;
    resource_t resources[COUNT];
} player_t;
