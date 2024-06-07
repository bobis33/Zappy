/*
** EPITECH PROJECT, 2024
** Server
** File description:
** clock
*/

#pragma once

typedef struct server_clock_s {
    struct timespec value;
    int freq;
} server_clock_t;

int get_ticks_elapsed(server_clock_t *clock);
