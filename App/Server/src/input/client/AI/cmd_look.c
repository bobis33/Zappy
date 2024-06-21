/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_look
*/

#include "Server/cmd_ai_client.h"
#include <string.h>

static void look_west(player_t *player, game_t *game)
{
    (void)game;
    print_msg(player->fd_client, "ok\n");
}

static void look_east(player_t *player, game_t *game)
{
    (void)game;
    print_msg(player->fd_client, "ok\n");
}

static void look_south(player_t *player, game_t *game)
{
    (void)game;
    print_msg(player->fd_client, "ok\n");
}

const char *resource_type_to_string(resource_type_t type)
{
    switch (type) {
        case FOOD:
            return "food";
        case LINEMATE:
            return "linemate";
        case DERAUMERE:
            return "deraumere";
        case SIBUR:
            return "sibur";
        case MENDIANE:
            return "mendiane";
        case PHIRAS:
            return "phiras";
        case THYSTAME:
            return "thystame";
        default:
            return "unknown";
    }
}

static void look_north(player_t *player, game_t *game)
{
    print_msg(player->fd_client, "[");
    int first_tile = 1;
    for (int i = 0; i <= player->level; ++i) {
        for (int j = -i; j <= i; ++j) {
            int tile_y = (player->position.y - i + game->map->height) % game->map->height;
            int tile_x = (player->position.x + j + game->map->width) % game->map->width;
            tile_t *tile = &game->map->tiles[tile_y][tile_x];
            if (!first_tile) {
                print_msg(player->fd_client, ", ");
            }
            int first_resource = 1;
            char tile_contents[1024] = {0};
            printf("tile is (%d, %d)\n", tile_x, tile_y);
            for (int k = 0; k < COUNT; ++k) {
                if (tile->resources[k].quantity > 0) {
                    if (!first_resource) {
                        strcat(tile_contents, " ");
                    }
                    strcat(tile_contents, resource_type_to_string(tile->resources[k].type));
                    first_resource = 0;
                }
            }
            if (strlen(tile_contents) == 0) {
                strcat(tile_contents, "");
            }
            print_msg(player->fd_client, tile_contents);
            first_tile = 0;
        }
    }
    print_msg(player->fd_client, "]\n");
}

void cmd_look(player_t *player, game_t *game)
{
    switch (player->direction) {
        case NORTH:
            look_north(player, game);
            break;
        case SOUTH:
            look_south(player, game);
            break;
        case EAST:
            look_east(player, game);
            break;
        case WEST:
            look_west(player, game);
            break;
        default:
            print_msg(player->fd_client, "ko\n");
            break;
    }
}
