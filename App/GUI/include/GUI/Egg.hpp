/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Egg
*/

#pragma once

namespace gui {

    class Egg {
        public:
            Egg(unsigned int id, int playerId, unsigned int x, unsigned int y) : m_id(id), m_playerId(playerId), m_x(x), m_y(y) {};
            ~Egg() = default;

            [[nodiscard]] unsigned int getId() const { return m_id; };
            [[nodiscard]] int getPlayerId() const { return m_playerId; };
            [[nodiscard]] unsigned int getX() const { return m_x; };
            [[nodiscard]] unsigned int getY() const { return m_y; };

        private:
            unsigned int m_id;
            int m_playerId;
            unsigned int m_x;
            unsigned int m_y;

    }; // class Egg

} // namespace gui