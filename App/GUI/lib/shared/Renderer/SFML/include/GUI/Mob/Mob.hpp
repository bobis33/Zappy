/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Mob
*/

#pragma once

#include "GUI/Mob/Inventory/Inventory.hpp"
#include "GUI/Position.hpp"

namespace gui {

    class Mob {

        public:

            enum class Action {
                MOVE,
                FEED,
                ELEVATE,
                NONE
            };

            Action getAction() const { return m_action; };
            Inventory& getInventory() { return m_inventory; };
            Position& getPosition() { return m_position; };
            unsigned int getLevel() const { return m_level; };

            void setAction(const Action &action) { m_action = action; };

            void levelUp() { m_level++; };

        private:

            Action m_action{Action::NONE};
            Inventory m_inventory;
            Position m_position;
            unsigned int m_level{1};

    }; // class Mob

} // namespace gui
