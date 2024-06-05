/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** main.c
*/

#include <stdlib.h>
#include <stdio.h>

#include "Server/parser.h"
#include "Server/server.h"

static void debug_print(arguments_t *args)
{
    printf("\n===============DEBUG SERVER===============\n");
    printf("port: %d\n", args->port);
    printf("width: %d\n", args->width);
    printf("height: %d\n", args->height);
    printf("clients_nb: %d\n", args->clients_nb);
    printf("freq: %d\n", args->freq);
    for (int i = 0; i < args->nb_teams; i++) {
        printf("team_names: %s\n", args->team_names[i]);
    }
    printf("==========================================\n\n");
}

static void free_server(arguments_t *args)
{
    for (int i = 0; i < args->nb_teams; i++) {
        free((void *)args->team_names[i]);
    }
    free((void *)args->team_names);
    free(args);
}

int main(const int argc, char *const argv[])
{
    arguments_t *args = NULL;

    if (!parse_args(&args, argc, argv)) {
        return EPITECH_EXIT_ERROR;
    }
    debug_print(args);
    if (!run_server(args)) {
        free_server(args);
        return EPITECH_EXIT_ERROR;
    }
    free_server(args);
    return EPITECH_EXIT_SUCCESS;
}
