/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Position
*/

#pragma once

namespace gui {

    class Position {

        public:

            Position() = default;

            Position(unsigned int cx, unsigned int cy) : x(cx), y(cy) {};
            ~Position() = default;

            unsigned int x;
            unsigned int y;

    }; // class Position

} // namespace 
