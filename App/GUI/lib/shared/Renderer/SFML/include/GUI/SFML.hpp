/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** SFML
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "GUI/Abstraction/ARenderer.hpp"
#include "GUI/SFMLClient.hpp"
#include "GUI/Constant.hpp"

namespace gui {

class SFML : public ARenderer {

        public:

            SFML() = default;
            ~SFML() override = default;

            [[nodiscard]] std::string getPluginName() const override { return PLUGIN_RENDERER_SFML.data(); };

            [[nodiscard]] IClient& getClient() override { return m_client; };

            void render() override;
            void handleEvents() override;
            bool checkConnection(sf::Clock clock, bool &connexionReceived);

        private:

            sf::RenderWindow m_window;
            SFMLClient m_client;
            bool m_isConnected{true};


    }; // class SFML

} // namespace sfml
