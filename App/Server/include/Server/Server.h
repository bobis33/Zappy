/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** Server
*/

#pragma once

typedef struct flag_binding_s {
    int flag;
    int (*binding)(int *value, char *arg);
} flag_binding_t;
