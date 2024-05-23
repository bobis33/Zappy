/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** SFML
*/

#pragma once

#include "GUI/Abstraction/ARenderer.hpp"
#include "GUI/Client.hpp"

namespace gui {

class SFML : public ARenderer {

        public:

            SFML() = default;
            ~SFML() override = default;

            [[nodiscard]] std::string getPluginName() const override { return "SFML"; };

            void connect(uint16_t port, const std::string& machineName) override;
            void render() override;

        private:

            Client m_client;

    }; // class SFML

} // namespace sfml
