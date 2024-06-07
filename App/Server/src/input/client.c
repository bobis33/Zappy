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

const cmd_builtin_client_t cmd_builtin[] = {
    {"msz\n", cmd_map_size},
    {"bct", cmd_tile_content},
    {"mct\n", cmd_map_tile_content},
    {"tna\n", cmd_team_names},
    {"ppo", cmd_player_pos},
    {"plv", cmd_player_lvl},
    {"pin", cmd_player_inventory},
    {"sgt\n", cmd_frequence},
    {"sst", cmd_frequence_update},
    {NULL, NULL}
};

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

static char **command_splitting(char *cmd, char **cmd_args)
{
    char *full_cmd = strtok(cmd, " ");

    for (int i = 0; full_cmd != NULL; i++) {
        cmd_args[i] = malloc(sizeof(char) * strlen(full_cmd) + 1);
        strcpy(cmd_args[i], full_cmd);
        full_cmd = strtok(NULL, " ");
        cmd_args = realloc(cmd_args, sizeof(char *) * (unsigned long)(i + 2));
        cmd_args[i + 1] = NULL;
    }
    return cmd_args;
}

static void cmd_builtin_client(
    game_t *game,
    client_t *client,
    char *cmd,
    const int fd)
{
    data_t *client_data;
    char **cmd_args = malloc(sizeof(char *) + 1);

    client_data = get_client_by_fd(client, fd);
    if (client_data->identity == NONE &&
        !identify_client(game, client_data, cmd, fd)) {
        free(cmd_args);
        return;
    }
    cmd_args = command_splitting(cmd, cmd_args);
    for (int i = 0; cmd_builtin[i].command; i++) {
        if (strcmp(cmd, cmd_builtin[i].command) == 0) {
            cmd_builtin[i].function(fd, cmd_args);
            free_array(cmd_args);
            return;
        }
    }
    print_msg(fd, "Unknown command: ");
    print_msg(fd, cmd);
    free_array(cmd_args);
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
