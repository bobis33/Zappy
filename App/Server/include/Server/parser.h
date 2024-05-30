/*
** EPITECH PROJECT, 2024
** Server
** File description:
** parser
*/

#pragma once

#include <stdbool.h>

#include "Server/arguments.h"

bool parse_args(arguments_t **args, const int ac, char *const av[]);
