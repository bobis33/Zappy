/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** bind
*/

#include <stdlib.h>

#include "Server/Bind.h"

int bind_port(int *port, char *arg)
{
    *port = atoi(arg);
    return 0;
}

int bind_width(int *width, char *arg)
{
    *width = atoi(arg);
    return 0;
}

int bind_height(int *height, char *arg)
{
    *height = atoi(arg);
    return 0;
}

int bind_team_names(int *team_names, char *arg)
{
    *team_names = atoi(arg);
    return 0;
}

int bind_clients_nb(int *clients_nb, char *arg)
{
    *clients_nb = atoi(arg);
    return 0;
}

int bind_freq(int *freq, char *arg)
{
    *freq = atoi(arg);
    return 0;
}
