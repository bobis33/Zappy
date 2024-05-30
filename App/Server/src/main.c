/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** main.c
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "Server/Constant.h"
#include "Server/Server.h"
#include "Server/Bind.h"

static const flag_binding_t FLAG_BINDING[] = {
    {.flag = 'p', .binding = &bind_port},
    {.flag = 'x', .binding = &bind_width},
    {.flag = 'y', .binding = &bind_height},
    {.flag = 'n', .binding = &bind_team_names},
    {.flag = 'c', .binding = &bind_clients_nb},
    {.flag = 'f', .binding = &bind_freq},
    {0}
};

static void print_help()
{
    write(1, "USAGE: ./zappy_server -p port -x width -y height "
             "-n name1 name2 ... -c clientsNb -f freq\n"
             "\tport\tis the port number\n"
             "\twidth\tis the width of the world\n"
             "\theight\tis the height of the world\n"
             "\tnameX\tis the name of the team X\n"
             "\tclientsNb\tis the number of authorized clients per team\n"
             "\tfreq\tis the reciprocal of time unit for execution of actions\n",
             333);
}

int main(int argc, char* const argv[])
{
    (void) FLAG_BINDING;
    int c = 0;

    server_t *server = malloc(sizeof(server_t));

    if (argc == 2 && strcmp(argv[1], "-help") == 0)
    {
        print_help();
        return EPITECH_EXIT_SUCCESS;
    }

    while ((c = getopt(argc, argv, "p:x:y:n:c:f:")) != -1)
    {
        if ('n' == c)
        {
            optind--;
            for ( ; *argv[optind] != 0 && *argv[optind] != '-'; optind++)
            {
                if (strstr(argv[optind], "-") != NULL)
                {
                    break;
                }
                bind_team_names(server, argv[optind]);
            }
        }
        for (unsigned int i = 0; FLAG_BINDING[i].flag; i++)
        {
            if (FLAG_BINDING[i].flag == c)
            {
                if ('n' == c)
                    break;
                FLAG_BINDING[i].binding(server, optarg);
            }
        }
    }

    printf("port: %d\n", server->port);
    printf("width: %d\n", server->width);
    printf("height: %d\n", server->height);
    printf("clients_nb: %d\n", server->clients_nb);
    printf("freq: %d\n", server->freq);
    for(int i = 0; i < server->team_names_len; i++)
    {
        printf("team_names: %s\n", server->team_names[i]);
    }

    return EPITECH_EXIT_SUCCESS;
}