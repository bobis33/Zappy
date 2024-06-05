/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** tools
*/

#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

bool is_perror(const int is_perror, const char *msg)
{
    if (is_perror == -1) {
        perror(msg);
        return true;
    }
    return false;
}

bool print_msg(const int fd, const char *msg)
{
    return write(fd, msg, strlen(msg)) != -1;
}
