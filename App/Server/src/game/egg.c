/*
** EPITECH PROJECT, 2024
** Server
** File description:
** egg
*/

#include "Server/Game/egg.h"

egg_t create_egg(
    int id,
    int laid_time,
    char *team_name,
    position_t pos)
{
    egg_t egg = {id, -1, laid_time, team_name, pos};

    return egg;
}
