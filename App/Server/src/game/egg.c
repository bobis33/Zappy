/*
** EPITECH PROJECT, 2024
** Server
** File description:
** egg
*/

#include "Server/Game/egg.h"

egg_t create_egg(
    int id,
    server_clock_t *laid_time,
    char *team_name,
    position_t pos)
{
    egg_t egg = {id, -1, team_name, {pos.x, pos.y}, laid_time};

    return egg;
}
