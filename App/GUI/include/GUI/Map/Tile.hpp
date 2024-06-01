/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Tile
*/

#pragma once

#include <utility>

#include "GUI/Inventory/Inventory.hpp"
#include "GUI/Position.hpp"

namespace gui {

    class Tile {

        public:

            Tile(Inventory inventory, const Position& position) : m_inventory(std::move(inventory)), m_position(position) {};
            ~Tile() = default;

            [[nodiscard]] Inventory getInventory() const { return m_inventory; };
            void setInventory(Inventory inventory) { m_inventory = std::move(inventory); };
            [[nodiscard]] Position getPosition() const { return m_position; };

        private:

            Inventory m_inventory;
            Position m_position;

    }; // class Tile

} // namespace gui
