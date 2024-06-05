/*
** EPITECH PROJECT, 2024
** Server
** File description:
** bind_team
*/

#include <string.h>
#include <stdlib.h>

#include "Server/arguments.h"

bool bind_team(arguments_t *args, char *arg)
{
    char *new_team_name = NULL;

    new_team_name = strdup(arg);
    if (!new_team_name) {
        return false;
    } else if (!args->team_names) {
        free(new_team_name);
        return false;
    }
    args->nb_teams++;
    if (args->nb_teams == 10) {
        free(new_team_name);
        return false;
    }
    args->team_names[args->nb_teams - 1] = new_team_name;
    return true;
}
