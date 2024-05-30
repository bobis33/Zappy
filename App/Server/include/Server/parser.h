/*
** EPITECH PROJECT, 2024
** Server
** File description:
** parser
*/

#pragma once

#include <stdbool.h>

#include "Server/server.h"

bool parse_args(server_t **server, const int ac, char *const av[]);
