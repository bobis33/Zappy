/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** bind.h
*/

#pragma once

#include <stdbool.h>

#include "Server/arguments.h"

bool bind_port(arguments_t *args, char *arg);
bool bind_width(arguments_t *args, char *arg);
bool bind_height(arguments_t *args, char *arg);
bool bind_team(arguments_t *args, char *arg);
bool bind_clients_nb(arguments_t *args, char *arg);
bool bind_freq(arguments_t *args, char *arg);

const flag_binding_t FLAG_BINDING[] = {
    {.flag = 'p', .binding = &bind_port},
    {.flag = 'x', .binding = &bind_width},
    {.flag = 'y', .binding = &bind_height},
    {.flag = 'n', .binding = &bind_team},
    {.flag = 'c', .binding = &bind_clients_nb},
    {.flag = 'f', .binding = &bind_freq},
    {0}
};
