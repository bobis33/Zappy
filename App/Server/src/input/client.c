/*
** EPITECH PROJECT, 2024
** Server
** File description:
** client
*/

#include <unistd.h>
#include <stdio.h>

#include "Server/client.h"
#include "Server/tools.h"

bool client_inputs(const int fd)
{
    char buffer[MAX_BUFFER_SIZE] = "\0";
    ssize_t read_value = read(fd, buffer, sizeof(buffer));

    switch (read_value) {
        case ERROR:
            perror("read");
            return false;
        case 0:
            return false;
        default:
            print_msg(1, "ok\n");
            return true;
    }
}
