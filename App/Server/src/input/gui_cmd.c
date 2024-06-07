/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** gui_cmd
*/

#include "Server/tools.h"
#include "Server/cmd_gui_client.h"
#include <string.h>

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

void cmd_gui_client(game_t *game, client_t *client, char *cmd, const int fd)
{
    char **cmd_args = malloc(sizeof(char *) + 1);

    (void)game;
    (void)client;
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
