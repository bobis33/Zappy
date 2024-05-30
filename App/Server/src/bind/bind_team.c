/*
** EPITECH PROJECT, 2024
** Server
** File description:
** bind_team
*/

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Server/server.h"

bool bind_team(server_t *server, char *arg)
{
    char *new_team_name = NULL;

    new_team_name = strdup(arg);
    if (!new_team_name) {
        return false;
    } else if (!server->team_names) {
        free(new_team_name);
        return false;
    }
    server->nb_teams++;
    if (server->nb_teams == 10) {
        free(new_team_name);
        return false;
    }
    server->team_names[server->nb_teams - 1] = new_team_name;
    return true;
}
