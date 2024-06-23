/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_inventory
*/

#include "Server/cmd_ai_client.h"

void cmd_inventory(player_t *player, game_t *game)
{
    char *inventory = malloc(sizeof(char) * 1024);

    (void)game;
    snprintf(inventory, 1024, "[food %d, linemate %d, deraumere %d,"
        "sibur %d, mendiane %d, phiras %d, thystame %d]\n",
        player->resources[0].quantity, player->resources[1].quantity,
        player->resources[2].quantity, player->resources[3].quantity,
        player->resources[4].quantity, player->resources[5].quantity,
        player->resources[6].quantity);
    add_action_to_player(player, ACTION, inventory, 1);
}
