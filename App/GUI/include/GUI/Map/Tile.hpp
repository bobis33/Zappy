/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Tile
*/

#pragma once

#include "GUI/Inventory/Inventory.hpp"
#include "GUI/Position.hpp"

namespace gui {

    class Tile {

        public:

            Tile(Inventory inventory, const Position& position) : m_inventory(std::move(inventory)), m_position(position) {};
            Tile(const Tile& tile) = default;
            ~Tile() = default;

            Tile() : m_inventory(Inventory({Resource::Type::FOOD, 0}, {Resource::Type::LINEMATE, 0},
                                           {Resource::Type::DERAUMERE, 0}, {Resource::Type::SIBUR, 0},
                                           {Resource::Type::MENDIANE, 0}, {Resource::Type::PHIRAS, 0},
                                           {Resource::Type::THYSTAME, 0})),
                     m_position(Position(0, 0)){};

            [[nodiscard]] Inventory getInventory() const { return m_inventory; };
            void setInventory(Inventory inventory) { m_inventory = std::move(inventory); };
            [[nodiscard]] Position getPosition() const { return m_position; };
            void setPosition(Position position) { m_position = position; };

        private:

            Inventory m_inventory;
            Position m_position;

    }; // class Tile

} // namespace gui
