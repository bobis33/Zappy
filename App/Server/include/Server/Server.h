/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** Server
*/

#pragma once

typedef struct server_s {
    int port;
    int width;
    int height;
    char **team_names;
    int team_names_len;
    int clients_nb;
    int freq;
} server_t;

typedef struct flag_binding_s {
    int flag;
    int (*binding)(server_t *server, char *arg);
} flag_binding_t;
