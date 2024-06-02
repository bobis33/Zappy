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

            Map(unsigned int width, unsigned int height, const std::vector<std::vector<Tile>>& tiles) : m_width(width), m_height(height), m_tiles(tiles) {};
            ~Map() = default;

            [[nodiscard]] unsigned int getWidth() const { return m_width; };
            [[nodiscard]] unsigned int getHeight() const { return m_height; };
            void setWidth(unsigned int width) { m_width = width; };
            void setHeight(unsigned int height) { m_height = height; };
            void addTile(const Tile& tile) { m_tiles.at(tile.getPosition().x).at(tile.getPosition().y) = tile; };

            [[nodiscard]] std::vector<std::vector<Tile>>& getTiles() { return m_tiles; };

        private:

            unsigned int m_width;
            unsigned int m_height;

            std::vector<std::vector<Tile>> m_tiles;

    }; // class Map

} // namespace gui
