/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** cmd_look
*/

#include <string.h>

#include "Server/cmd_ai_client.h"

static const char *resource_type_to_string(resource_type_t type)
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

static void get_tile_resources(char *msg, tile_t *tile)
{
    for (int i = 0; i < 7; i++) {
        if (tile->resources[i]->quantity < 0) {
            continue;
        }
        for (int j = 0; j < tile->resources[i]->quantity; j++) {
            strcat(msg, " ");
            strcat(msg, resource_type_to_string(tile->resources[i]->type));
        }
    }
}

static void get_adjacent_tile_resources(char *msg, game_t *game, int x, int y)
{
    if (x < 0) {
        x += game->map->width;
    } else if (x >= game->map->width) {
        x -= game->map->width;
    }
    if (y < 0) {
        y += game->map->height;
    } else if (y >= game->map->height) {
        y -= game->map->height;
    }
    strcat(msg, ",");
    for (int i = 0; i < game->map->height * game->map->width; i++) {
        if (game->map->tiles[i]->pos->x == x &&
            game->map->tiles[i]->pos->y == y) {
            get_tile_resources(msg, game->map->tiles[i]);
            break;
        }
    }
}

static void look_direction(
    player_t *player,
    game_t *game,
    int dx[3],
    int dy[3])
{
    char msg[10240];
    int x = player->position.x;
    int y = player->position.y;

    msg[0] = '\0';
    strcat(msg, "[player");
    for (int i = 0; i < game->map->height * game->map->width; i++) {
        if (game->map->tiles[i]->pos->x == x &&
            game->map->tiles[i]->pos->y == y) {
            get_tile_resources(msg, game->map->tiles[i]);
            break;
        }
    }
    for (int i = 0; i < 3; i++) {
        get_adjacent_tile_resources(msg, game, x + dx[i], y + dy[i]);
    }
    strcat(msg, "]\n");
    add_action_to_player(player, ACTION, msg, 7);
}

static void look_north(player_t *player, game_t *game)
{
    int dx[3] = {-1, 0, 1};
    int dy[3] = {-1, -1, -1};

    look_direction(player, game, dx, dy);
}

static void look_south(player_t *player, game_t *game)
{
    int dx[3] = {-1, 0, 1};
    int dy[3] = {1, 1, 1};

    look_direction(player, game, dx, dy);
}

static void look_east(player_t *player, game_t *game)
{
    int dx[3] = {1, 1, 1};
    int dy[3] = {-1, 0, 1};

    look_direction(player, game, dx, dy);
}

static void look_west(player_t *player, game_t *game)
{
    int dx[3] = {-1, -1, -1};
    int dy[3] = {-1, 0, 1};

    look_direction(player, game, dx, dy);
}

void cmd_look(player_t *player, game_t *game)
{
    static struct {
        orientation_t direction;
        void (*look_func)(player_t *player, game_t *game);
    } look_functions[] = {
            {NORTH, look_north},
            {EAST, look_east},
            {SOUTH, look_south},
            {WEST, look_west},
    };

    for (int i = 0; i < 4; i++) {
        if (look_functions[i].direction == player->direction) {
            look_functions[i].look_func(player, game);
            break;
        }
    }
}
