/*
** EPITECH PROJECT, 2024
** B-YEP-400-BDX-4-1-zappy-jules.sourbets
** File description:
** main.c
*/

#include <stdio.h>

#include "Server/Constant.h"

int main(int argc, char* argv[])
{
    if (argc == 2 && argv[1] != "-help")
        return EPITECH_EXIT_ERROR;
    if (argc < 13)
        return EPITECH_EXIT_ERROR;
    (void)argc;
    (void)argv;
    return EPITECH_EXIT_SUCCESS;
}