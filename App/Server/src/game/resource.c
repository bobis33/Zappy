/*
** EPITECH PROJECT, 2024
** Server
** File description:
** resource
*/

#include "Server/Game/game.h"

void add_resource(map_t *map, resource_t resource)
{
    int y = rand() % map->height;
    int x = rand() % map->width;

    x *= y;
    map->tiles[x]->resources[resource.type]->quantity++;
}
