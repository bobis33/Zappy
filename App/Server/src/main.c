/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** main.c
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "Server/constant.h"
#include "Server/server.h"
#include "Server/parser.h"

int main(const int argc, char *const argv[])
{
    server_t *server = NULL;

    if (!parse_args(&server, argc, argv)) {
        return EPITECH_EXIT_ERROR;
    }
    printf("port: %d\n", server->port);
    printf("width: %d\n", server->width);
    printf("height: %d\n", server->height);
    printf("clients_nb: %d\n", server->clients_nb);
    printf("freq: %d\n", server->freq);
    for (int i = 0; i < server->nb_teams; i++) {
        printf("team_names: %s\n", server->team_names[i]);
    }
    free((void *)server->team_names);
    free(server);
    return EPITECH_EXIT_SUCCESS;
}
