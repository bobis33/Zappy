/*
** EPITECH PROJECT, 2024
** Server
** File description:
** action
*/

#pragma once

#include "Server/Game/clock.h"

typedef enum action_type_s {
    ACTION,
    INCANTATION,
    NOTHING
} action_type_t;

typedef struct action_s {
    action_type_t type;
    int duration;
    char *msg;
    server_clock_t *clock;

    struct action_s *next;
} action_t;
