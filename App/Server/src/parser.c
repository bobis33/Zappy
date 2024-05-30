/*
** EPITECH PROJECT, 2024
** Server
** File description:
** parser
*/

#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "Server/server.h"
#include "Server/tools.h"
#include "Server/bind.h"
#include "Server/constant.h"

static server_t *init_struct(void)
{
    server_t *server = malloc(sizeof(server_t));

    server->port = 0;
    server->width = 0;
    server->height = 0;
    server->nb_teams = 0;
    server->clients_nb = 0;
    server->freq = DEFAULT_FREQ;
    server->team_names = malloc(sizeof(char *) * MAX_TEAMS);
    if (!server->team_names) {
        free(server);
        return NULL;
    }
    return server;
}

static bool parse_flag_help(const int argc, char *argv)
{
    if (argc == 2 && strcmp(argv, "-help") == 0) {
        if (!print_msg(1, "USAGE: ./zappy_server -p port -x width -y height "
            "-n name1 name2 ... -c clientsNb -f freq\n"
            "\tport\tis the port number\n"
            "\twidth\tis the width of the world\n"
            "\theight\tis the height of the world\n"
            "\tnameX\tis the name of the team X\n"
            "\tclientsNb\tis the number of authorized clients per team\n"
            "\tfreq\tis the reciprocal of time unit "
            "for execution of actions\n")) {
            return false;
        }
        exit(0);
        return true;
    }
    return true;
}

static void parse_flags(char *const argv[],
    server_t **server,
    const int option_char)
{
    for (unsigned int i = 0; FLAG_BINDING[i].flag; i++) {
        if (FLAG_BINDING[i].flag == option_char && 'n' != option_char) {
            FLAG_BINDING[i].binding(*server, optarg);
        }
    }
    if ('n' != option_char) {
        return;
    }
    optind--;
    for (; *argv[optind] != 0 && *argv[optind] != '-'; optind++) {
        if (strstr(argv[optind], "-") != NULL) {
            break;
        }
        bind_team(*server, argv[optind]);
    }
}

bool parse_args(server_t **server, const int argc, char *const argv[])
{
    int option_char = 0;

    if (!parse_flag_help(argc, argv[1]))
        return false;
    *server = init_struct();
    if (!server) {
        return false;
    }
    while (true) {
        option_char = getopt(argc, argv, "p:x:y:n:c:f:");
        if (option_char == -1) {
            break;
        }
        parse_flags(argv, server, option_char);
    }
    return true;
}
