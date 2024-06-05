/*
** EPITECH PROJECT, 2024
** Server
** File description:
** client
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "Server/client.h"
#include "Server/tools.h"
#include "Server/cmd_client.h"

void cmd_builtin_client(const char *cmd, const int fd)
{
    cmd_builtin_client_t cmd_builtin[] = {
            {NULL, NULL}
    };

    for (int i = 0; cmd_builtin[i].command; i++) {
        if (strcmp(cmd, cmd_builtin[i].command) == 0) {
            cmd_builtin[i].function();
            return;
        }
    }
    print_msg(fd, "Unknown command: ");
    print_msg(fd, cmd);
}

bool client_inputs(const int fd)
{
    char cmd[MAX_BUFFER_SIZE] = "\0";
    ssize_t read_value = read(fd, cmd, sizeof(cmd));

    switch (read_value) {
        case ERROR:
            perror("read");
            return false;
        case 0:
            return false;
        default:
            cmd_builtin_client(cmd, fd);
            return true;
    }
}
