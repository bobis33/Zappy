/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** arguments.h
*/

#pragma once

#include <stdbool.h>

typedef struct arguments_s {
    u_int16_t port;
    int width;
    int height;
    int nb_teams;
    int clients_nb;
    int freq; // DEFAULT 100
    char **team_names;
} arguments_t;

typedef struct flag_binding_s {
    int flag;
    bool (*binding)(arguments_t *args, char *arg);
} flag_binding_t;
