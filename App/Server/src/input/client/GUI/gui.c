/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** gui_cmd
*/

#include <string.h>

#include "Server/cmd_gui_client.h"
#include "Server/tools.h"

const cmd_builtin_client_t cmd_builtin[] = {
    {"msz\n", cmd_map_size},
    {"bct", cmd_tile_content},
    {"mct\n", cmd_map_tile_content},
    {"tna\n", cmd_team_names},
    {"ppo", cmd_player_pos},
    {"plv", cmd_player_lvl},
    {"pin", cmd_player_inventory},
    {"sgt\n", cmd_frequency},
    {"sst", cmd_frequency_update},
    {NULL, NULL}
};

static char **parse_command(char *cmd, char **cmd_array)
{
    char *token = strtok(cmd, " ");

    for (int i = 0; token != NULL; i++) {
        cmd_array[i] = malloc(sizeof(char) * strlen(token) + 1);
        strcpy(cmd_array[i], token);
        token = strtok(NULL, " ");
        cmd_array = realloc(cmd_array, sizeof(char *) *(unsigned long)(i + 2));
        cmd_array[i + 1] = NULL;
    }
    return cmd_array;
}

void cmd_gui_client(game_t *game, char *cmd, const int fd)
{
    char **cmd_array = malloc(sizeof(char *) + 1);

    cmd_array = parse_command(cmd, cmd_array);
    for (int i = 0; cmd_builtin[i].command; i++) {
        if (strcmp(cmd, cmd_builtin[i].command) == 0) {
            cmd_builtin[i].function(fd, cmd_array, game);
            free_array(cmd_array);
            return;
        }
    }
    print_msg(fd, "Unknown command: ");
    print_msg(fd, cmd);
    free_array(cmd_array);
}
