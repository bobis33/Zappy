/*
** EPITECH PROJECT, 2024
** Server
** File description:
** client_tools
*/

#include <unistd.h>
#include <stdlib.h>

#include "Server/client.h"
#include "Server/tools.h"

bool create_client(client_t *client, int server_fd, int new_fd)
{
    new_fd = accept(server_fd,
        (struct sockaddr *) &client->socket, &client->client_len);
    if (is_perror(new_fd, "accept")) {
        free(client);
        return false;
    }
    if (client->clients[MAX_CLIENTS - 1].fd != ERROR) {
        close(new_fd);
        return ERROR;
    }
    client->max_fd = (new_fd > client->max_fd) ? new_fd : client->max_fd;
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client->clients[i].fd == ERROR) {
            client->clients[i].fd = new_fd;
            FD_SET(new_fd, &client->master_fds);
            print_msg(new_fd, "WELCOME\n");
            return true;
        }
    }
    return false;
}

data_t *get_client_by_fd(client_t *client, int fd)
{
    for (register int index = 0; index < MAX_CLIENTS; index++) {
        if (client->clients[index].fd == fd) {
            return &client->clients[index];
        }
    }
    return NULL;
}

void remove_client(client_t *client, int fd)
{
    data_t *client_data = get_client_by_fd(client, fd);

    close(fd);
    FD_CLR(fd, &client->master_fds);
    if (client_data != NULL) {
        client_data->fd = ERROR;
    }
}
