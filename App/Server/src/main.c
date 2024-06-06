/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** main.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

#include "Server/parser.h"
#include "Server/server.h"
#include "Server/game.h"

static void my_handler(int signal)
{
    (void) signal;
    *stop_signal_catched() = true;
}

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
    game_t *game = NULL;
    struct sigaction sigIntHandler = {0};

    sigIntHandler.sa_handler = my_handler;
    sigemptyset(&sigIntHandler.sa_mask);
    sigaction(SIGINT, &sigIntHandler, NULL);
    if (!parse_args(&args, argc, argv)) {
        return EPITECH_EXIT_ERROR;
    }
    init_game(args, &game);
    debug_print(args);
    if (!run_server(args)) {
        free_server(args);
        return EPITECH_EXIT_ERROR;
    }
    free_game_resources(game);
    free_server(args);
    return EPITECH_EXIT_SUCCESS;
}
