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

static bool identify_client(
    game_t *game,
    data_t *client_data,
    const char *cmd,
    const int fd)
{
    char *tmp_team_name = NULL;

    if (strcmp(cmd, "GRAPHIC\n") == 0) {
        client_data->identity = GRAPHIC;
        return false;
    }
    for (int i = 0; i < game->nb_teams; i++) {
        tmp_team_name = malloc(strlen(game->team_names[i]) + 2);
        tmp_team_name = strcpy(tmp_team_name, game->team_names[i]);
        tmp_team_name = strcat(tmp_team_name, "\n");
        if (strcmp(cmd, tmp_team_name) == 0) {
            client_data->identity = AI;
            free(tmp_team_name);
            return false;
        }
        free(tmp_team_name);
    }
    print_msg(fd, "You have to identify ur client: GRAPHIC or [team_name]\n");
    return true;
}

static void cmd_builtin_client(
    game_t *game,
    client_t *client,
    const char *cmd,
    const int fd)
{
    data_t *client_data = get_client_by_fd(client, fd);
    cmd_builtin_client_t cmd_builtin[] = {
        {"sgt", cmd_frequence},
        {"tna", cmd_team_names},
        {"msz", cmd_map_size},
        {"mct", cmd_map_tile_content},
        {NULL, NULL}
    };

    if (client_data->identity == NONE &&
        !identify_client(game, client_data, cmd, fd)) {
        return;
    }
    for (int i = 0; cmd_builtin[i].command; i++) {
        if (strcmp(cmd, cmd_builtin[i].command) == 0) {
        cmd_builtin[i].function(fd, cmd);
        return;
        }
    }
    print_msg(fd, "Unknown command: ");
    print_msg(fd, cmd);
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
