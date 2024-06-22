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
                TAKE,
                DEATH,
                NONE
            };

            enum Orientation {
                NORTH = 1,
                EAST = 2,
                SOUTH = 3,
                WEST = 4,
                NONE = 0
            };

            Player() = default;
            ~Player() = default;

            [[nodiscard]] Action getAction() const { return m_action; };
            [[nodiscard]] Action getLastAction() const { return m_lastAction; };
            [[nodiscard]] Orientation getOrientation() const { return m_orientation; };
            [[nodiscard]] Inventory& getInventory() { return m_inventory; };
            [[nodiscard]] Position& getPosition() { return m_position; };
            [[nodiscard]] Position& getLastPosition() { return m_lastPosition; };
            [[nodiscard]] unsigned int getLevel() const { return m_level; };
            [[nodiscard]] unsigned int getId() const { return m_id; };
            [[nodiscard]] std::string getTeamName() const { return m_teamName; };
            [[nodiscard]] Orientation getMoving() const { return m_moving; };

            void setAction(const Action action) { m_action = action; };
            void setLastAction(const Action lastAction) { m_lastAction = lastAction; };
            void setOrientation(const Orientation orientation) { m_orientation = orientation; };
            void setId(const unsigned int id) { m_id = id; };
            void setTeamName(const std::string &teamName) { m_teamName = teamName; };
            void setLevel(const unsigned int level) { m_level = level; };
            void setLastPosition(const Position &lastPosition) { m_lastPosition = lastPosition; };
            void setMoving(const Orientation moving) { m_moving = moving; };

            void levelUp() { m_level++; };

            int player_frame = 0;
            int index_moving = 0;

        private:

            Action m_action{Action::NONE};
            Action m_lastAction{Action::NONE};
            Inventory m_inventory;
            Position m_position;
            Position m_lastPosition;
            Orientation m_orientation{Orientation::NORTH};
            std::string m_teamName{""};
            unsigned int m_id{0};
            unsigned int m_level{1};
            bool isAlive{true};
            Orientation m_moving;

    }; // class Player

} // namespace gui
