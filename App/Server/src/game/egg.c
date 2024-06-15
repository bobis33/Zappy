/*
** EPITECH PROJECT, 2024
** Server
** File description:
** egg
*/

#include <stdlib.h>

#include "Server/Game/egg.h"

egg_t *create_egg(
    int id,
    int player_id,
    char *team_name,
    position_t pos)
{
    egg_t *egg = malloc(sizeof(egg_t));

    egg->id = id;
    egg->player_id = player_id;
    egg->team_name = team_name;
    egg->pos = pos;
    return egg;
}
