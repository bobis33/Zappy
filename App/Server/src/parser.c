/*
** EPITECH PROJECT, 2024
** Server
** File description:
** parser
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "Server/arguments.h"
#include "Server/tools.h"
#include "Server/bind.h"
#include "Server/constant.h"

static arguments_t *init_struct(void)
{
    arguments_t *args = malloc(sizeof(arguments_t));

    args->port = 0;
    args->width = 0;
    args->height = 0;
    args->nb_teams = 0;
    args->clients_nb = 0;
    args->freq = DEFAULT_FREQ;
    args->team_names = malloc(sizeof(char *) * MAX_TEAMS);
    if (!args->team_names) {
        free(args);
        return NULL;
    }
    return args;
}

static bool check_filled_struct(arguments_t *args)
{
    if (args->port == 0 || args->width == 0 ||
        args->height == 0 || args->nb_teams == 0 ||
        args->clients_nb == 0 || args->team_names[0] == NULL) {
        return false;
    }
    return true;
}

static bool parse_flag_help(const char *argv)
{
    if (strcmp(argv, "-help") == 0) {
        if (!print_msg(1, "USAGE: ./zappy_server -p port -x width -y height "
            "-n name1 name2 ... -c clientsNb -f freq\n"
            "\tport\t   is the port number\n"
            "\twidth\t   is the width of the world\n"
            "\theight\t   is the height of the world\n"
            "\tnameX\t   is the name of the team X\n"
            "\tclientsNb  is the number of authorized clients per team\n"
            "\tfreq\t   is the reciprocal of time unit "
            "for execution of actions\n")) {
            return false;
        }
        exit(0);
    }
    return true;
}

static void parse_flags(char *const argv[],
                        arguments_t **args,
                        const int option_char)
{
    for (unsigned int i = 0; FLAG_BINDING[i].flag; i++) {
        if (FLAG_BINDING[i].flag == option_char && 'n' != option_char) {
            FLAG_BINDING[i].binding(*args, optarg);
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
        bind_team(*args, argv[optind]);
    }
}

bool parse_args(arguments_t **args, const int argc, char *const argv[])
{
    int option_char = 0;

    if (argc == 2 && !parse_flag_help(argv[1])) {
        return false;
    }
    *args = init_struct();
    while (true) {
        option_char = getopt(argc, argv, "p:x:y:n:c:f:");
        if (option_char == -1 || option_char == '?') {
            break;
        }
        parse_flags(argv, args, option_char);
    }
    if (!check_filled_struct(*args)) {
        return false;
    }
    return true;
}
