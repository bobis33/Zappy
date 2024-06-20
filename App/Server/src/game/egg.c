/*
** EPITECH PROJECT, 2024
** Server
** File description:
** egg
*/

#include "Server/Game/egg.h"

egg_t create_egg(
    int id,
    char *team_name,
    server_clock_t laid_time,
    position_t pos)
{
    egg_t egg = {id, -1, laid_time, team_name, pos};

    return egg;
}
