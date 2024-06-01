/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Map.hpp
*/

#pragma once

#include <array>

#include "GUI/Constant.hpp"
#include "GUI/Map/Tile.hpp"

namespace gui {

    class Map {

        public:

            Map(unsigned int width, unsigned int height, std::array<std::array<Tile, MAX_MAP_SIZE>, MAX_MAP_SIZE> tiles) : m_width(width), m_height(height), m_tiles(tiles) {};
            ~Map();

            unsigned int getWidth() const { return m_width; };
            unsigned int getHeight() const { return m_height; };
            void setWidth(unsigned int width) { m_width = width; };
            void setHeight(unsigned int height) { m_height = height; };
            void addTile(Tile tile) { m_tiles[tile.getPosition().x][tile.getPosition().y] = tile; };

            std::array<std::array<Tile, MAX_MAP_SIZE>, MAX_MAP_SIZE> getTiles() const { return m_tiles; };

        private:

            unsigned int m_width;
            unsigned int m_height;

            std::array<std::array<Tile, MAX_MAP_SIZE>, MAX_MAP_SIZE> m_tiles;

    }; // class Map

} // namespace gui
