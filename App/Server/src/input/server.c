/*
** EPITECH PROJECT, 2024
** Server
** File description:
** server
*/

#include <stdio.h>
#include <string.h>

#include "Server/server.h"
#include "Server/cmd_server.h"
#include "Server/tools.h"

server_status_t cmd_builtin_server(const char *cmd)
{
    cmd_builtin_server_t cmd_builtin[] = {
        {"/quit\n", cmd_quit},
        {NULL, NULL}
    };

    for (int i = 0; cmd_builtin[i].command; i++) {
        if (strcmp(cmd, cmd_builtin[i].command) == 0) {
            return cmd_builtin[i].function();
        }
    }
    print_msg(1, "Unknown command: ");
    print_msg(1, cmd);
    return RUNNING;
}

server_status_t server_inputs(void)
{
    char *cmd = NULL;
    size_t len = 0;
    long value = getline(&cmd, &len, stdin);
    server_status_t r_value = 0;

    switch (value) {
        case ERROR:
            free(cmd);
            return STOPPED;
        case 0:
            free(cmd);
            return STOPPED;
        default:
            r_value = cmd_builtin_server(cmd);
            free(cmd);
            return r_value;
    }
    return RUNNING;
}
