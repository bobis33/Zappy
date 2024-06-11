/*
** EPITECH PROJECT, 2024
** Server
** File description:
** resource
*/

#pragma once

typedef enum resource_type_e {
    FOOD = 0,
    LINEMATE = 1,
    DERAUMERE = 2,
    SIBUR = 3,
    MENDIANE = 4,
    PHIRAS = 5,
    THYSTAME = 6,
    COUNT = 7
} resource_type_t;

typedef struct resource_s {
    int quantity;
    double density;
    resource_type_t type;
} resource_t;
