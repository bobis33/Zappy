/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** bind
*/

#include <stdlib.h>
#include <stdbool.h>

#include "Server/arguments.h"

bool bind_port(arguments_t *args, char *arg)
{
    args->port = atoi(arg);
    return true;
}

bool bind_width(arguments_t *args, char *arg)
{
    args->width = atoi(arg);
    return true;
}

bool bind_height(arguments_t *args, char *arg)
{
    args->height = atoi(arg);
    return true;
}

bool bind_clients_nb(arguments_t *args, char *arg)
{
    args->clients_nb = atoi(arg);
    return true;
}

bool bind_freq(arguments_t *args, char *arg)
{
    args->freq = atoi(arg);
    return true;
}
