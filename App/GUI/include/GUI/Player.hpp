/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Player.hpp
*/

#pragma once

#include "GUI/Inventory/Inventory.hpp"
#include "GUI/Position.hpp"

namespace gui {

    class Player {

        public:

            enum class Action {
                MOVE,
                FEED,
                ELEVATE,
                NONE
            };

            enum class Direction {
                UP,
                DOWN,
                LEFT,
                RIGHT
            };

            Action getAction() const { return m_action; };
            Direction getDirection() const { return m_direction; };
            Inventory& getInventory() { return m_inventory; };
            Position& getPosition() { return m_position; };
            unsigned int getLevel() const { return m_level; };

            void setAction(const Action action) { m_action = action; };
            void setDirection(const Direction direction) { m_direction = direction; };

            void levelUp() { m_level++; };

        private:

            bool m_isAlive{true};
            Action m_action{Action::NONE};
            Inventory m_inventory;
            Position m_position;
            Direction m_direction{Direction::UP};
            unsigned int m_level{1};

    }; // class Player

} // namespace gui
