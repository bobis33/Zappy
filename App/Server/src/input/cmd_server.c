/*
** EPITECH PROJECT, 2024
** zappy_server
** File description:
** cmd_server
*/

#include "Server/cmd_server.h"
#include "Server/tools.h"

server_status_t cmd_quit(void)
{
    print_msg(1, "Shutdown server ...\n");
    return STOPPED;
}
