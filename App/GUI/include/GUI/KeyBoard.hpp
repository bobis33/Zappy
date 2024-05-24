/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** KeyBoard
*/

#pragma once

namespace gui {

    class KeyBoard {

        public:

            enum Key {
                NONE = -1, // Keep this at the beginning
                CLOSE = 0,
                KEY_LEFT = 1,
                KEY_RIGHT = 2,
                KEY_UP = 3,
                KEY_DOWN = 4,
                KEY_SPACE = 5,
                KEY_ENTER = 6,
                KEY_ESCAPE = 7,
                COUNT = 8 // corresponding to the size of the enum, keep this at the end
        };

    }; // class KeyBoard

} // namespace gui
