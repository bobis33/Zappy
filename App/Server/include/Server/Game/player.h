/*
** EPITECH PROJECT, 2024
** Server
** File description:
** player
*/

#pragma once

#include <stdbool.h>

#include "Server/Game/resource.h"
#include "Server/Game/action.h"
#include "Server/Game/position.h"

typedef enum orientation_e {
    NORTH,
    EAST,
    SOUTH,
    WEST
} orientation_t;

typedef struct player_s {
    int level;
    int id;
    int fd_client;
    char *team_name;
    position_t position;
    orientation_t direction;
    resource_t resources[COUNT];
    action_t *action_queue;
    action_t *action_queue_tail;
} player_t;

player_t *create_player(char *team_name, int id, int pos_x, int pos_y);
action_t *create_action(action_type_t type, int duration);
void add_action_to_player(player_t *player, action_type_t type, int duration);
void execute_player_action(player_t *player);
bool is_current_action_done(player_t *player);

/* TO REMOVE - EXP USE FOR PLAYER_ACTION

action_t *create_action(action_type_t type, int duration)
{
    action_t *new_action = malloc(sizeof(action_t));
    if (!new_action) {
        return NULL;
    }
    new_action->type = type;
    new_action->duration = duration;
    new_action->next = NULL;
    return new_action;
}

void add_action_to_player(player_t *player, action_type_t type, int duration)
{
    action_t *new_action = create_action(type, duration);
    if (!new_action) {
        return;
    }

    if (!player->action_queue) {
        player->action_queue = new_action;
        player->action_queue_tail = new_action;
    } else {
        player->action_queue_tail->next = new_action;
        player->action_queue_tail = new_action;
    }
}

void execute_player_action(player_t *player)
{
    if (!player->action_queue) {
        return;
    }

    action_t *current_action = player->action_queue;

    player->action_queue = current_action->next;
    if (!player->action_queue) {
        player->action_queue_tail = NULL;
    }
    free(current_action);
}

bool is_current_action_done(player_t *player)
{
    if (!player->action_queue) {
        return true;
    }
    player->action_queue->duration--;
    return (player->action_queue->duration <= 0);
}

void game_tick(player_t *players, int num_players)
{
    for (int i = 0; i < num_players; i++) {
        if (is_current_action_done(&players[i])) {
            execute_player_action(&players[i]);
        }
    }
}

int main()
{
    player_t player = {
        .pos_x = 0,
        .pos_y = 0,
        .life_units = 1260,
        .direction = NORTH,
        .action_queue = NULL,
        .action_queue_tail = NULL
    };
    add_action_to_player(&player, ACTION, 5);
    add_action_to_player(&player, INCANTATION, 10);

    // Game loop (simplified)
    for (int tick = 0; tick < 20; tick++) {
        if (is_current_action_done(&player)) {
            execute_player_action(&player);
        }
    }
    return 0;
}
*/
