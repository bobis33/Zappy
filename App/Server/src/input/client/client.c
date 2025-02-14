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
#include "Server/cmd_ai_client.h"
#include "Server/cmd_gui_client.h"

static void ai_loop(game_t *game, const int fd, char *cmd)
{
    for (int i = 0; game->players[i] != NULL; i++) {
        if (game->players[i]->fd_client == fd) {
            cmd_ai_client(game->players[i], game, cmd);
            return;
        }
    }
}

static bool identify_client(
    game_t *game,
    data_t *client_data,
    const char *cmd,
    const int fd)
{
    char *tmp_team_name = NULL;

    if (strcmp(cmd, "GRAPHIC\n") == 0) {
        connect_gui(game, client_data, fd);
        return false;
    }
    for (int i = 0; i < game->nb_teams; i++) {
        tmp_team_name = malloc(strlen(game->team_names[i]) + 3);
        tmp_team_name = strcpy(tmp_team_name, game->team_names[i]);
        tmp_team_name = strcat(tmp_team_name, "\n");
        if (strcmp(cmd, tmp_team_name) == 0) {
            connect_ai(game, client_data, fd, game->team_names[i]);
            free(tmp_team_name);
            return false;
        }
        free(tmp_team_name);
    }
    return true;
}

static void cmd_builtin_client(
    game_t *game,
    client_t *client,
    char *cmd,
    const int fd)
{
    data_t *client_data = NULL;

    client_data = get_client_by_fd(client, fd);
    if (client_data->identity == NONE &&
        !identify_client(game, client_data, cmd, fd)) {
        return;
    }
    switch (client_data->identity) {
        case GRAPHIC:
            cmd_gui_client(game, cmd, fd);
            break;
        case AI:
            ai_loop(game, fd, cmd);
            break;
        default:
            break;
    }
}

bool client_inputs(game_t *game, client_t *client, const int fd)
{
    char cmd[MAX_BUFFER_SIZE] = {0};

    switch (read(fd, cmd, sizeof(cmd))) {
        case ERROR:
            perror("read");
            return false;
        case 0:
            return false;
        default:
            cmd_builtin_client(game, client, cmd, fd);
            return true;
    }
}
