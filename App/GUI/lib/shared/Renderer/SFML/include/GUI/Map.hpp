/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Map.hpp
*/

#pragma once

namespace gui {

    class Map {

        public:

            Map(unsigned int width, unsigned int height) : m_width(width), m_height(height) {};
            ~Map();

            unsigned int getWidth() const { return m_width; };
            unsigned int getHeight() const { return m_height; };

        private:

            unsigned int m_width;
            unsigned int m_height;

    }; // class Map

} // namespace gui
