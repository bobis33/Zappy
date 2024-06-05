/*
** EPITECH PROJECT, 2024
** Server
** File description:
** server
*/

#include <stdio.h>
#include <string.h>

#include "Server/server.h"

server_status_t server_inputs(void)
{
    char *cmd = NULL;
    size_t len = 0;
    long value = getline(&cmd, &len, stdin);

    switch (value) {
        case ERROR:
            perror("getline");
            return STOPPED;
        case 0:
            return STOPPED;
        default:
            if (strcmp(cmd, "/quit\n") == 0) {
                return STOPPED;
            }
            return RUNNING;
    }
}
