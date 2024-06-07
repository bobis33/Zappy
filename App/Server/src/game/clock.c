/*
** EPITECH PROJECT, 2024
** Server
** File description:
** clock
*/

#include <time.h>

#include "Server/Game/clock.h"
#include "Server/constant.h"

int get_ticks_elapsed(server_clock_t *clock)
{
    double ticks = 0;
    struct timespec new_val = {0};

    if (!clock) {
        return ERROR;
    }
    clock_gettime(CLOCK_MONOTONIC, (&new_val));
    ticks = ((double) (new_val.tv_sec - clock->value.tv_sec)) +
            ((double) (new_val.tv_nsec - clock->value.tv_nsec)) * 1e-9;
    return (int) (ticks * clock->freq);
}
