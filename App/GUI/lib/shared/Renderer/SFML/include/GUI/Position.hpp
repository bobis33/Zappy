/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Position
*/

#pragma once

#include <utility>

namespace {

    class Position {

        public:

            Position(unsigned int x, unsigned int y) : x(x), y(y) {};
            ~Position();

            unsigned int x;
            unsigned int y;

    }; // class Position

} // namespace 
