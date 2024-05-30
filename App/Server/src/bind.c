/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** bind
*/

#include <stdlib.h>
#include <string.h>

#include "Server/Bind.h"

int bind_port(server_t *server, char *arg)
{
    server->port = atoi(arg);
    return EXIT_SUCCESS;
}

int bind_width(server_t *server, char *arg)
{
    server->width = atoi(arg);
    return EXIT_SUCCESS;
}

int bind_height(server_t *server, char *arg)
{
    server->height = atoi(arg);
    return EXIT_SUCCESS;
}

int bind_team_names(server_t *server, char *arg)
{
    if (arg == NULL)
        return 1;

    char *new_team_name = strdup(arg);
    if (!new_team_name)
        return 1;

    server->team_names_len++;

    server->team_names = realloc(server->team_names, sizeof(char *) * server->team_names_len);
    if (!server->team_names) {
        free(new_team_name);
        return 1;
    }

    server->team_names[server->team_names_len - 1] = new_team_name;

    return EXIT_SUCCESS;
}


int bind_clients_nb(server_t *server, char *arg)
{
    server->clients_nb = atoi(arg);
    return EXIT_SUCCESS;
}

int bind_freq(server_t *server, char *arg)
{
    server->freq = atoi(arg);
    return 0;
}
