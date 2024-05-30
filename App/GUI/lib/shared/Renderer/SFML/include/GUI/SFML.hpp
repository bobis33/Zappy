/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** SFML
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <array>

#include "GUI/Abstraction/IRenderer.hpp"
#include "GUI/SFMLClient.hpp"
#include "GUI/KeyBoard.hpp"

namespace gui {

class SFML : public IRenderer {

        public:

            SFML() = default;
            ~SFML() override = default;

            void setFPS(const unsigned int FPS) override { m_window.setFramerateLimit(FPS); };

            [[nodiscard]] std::string getPluginName() const override { return PLUGIN_RENDERER_SFML.data(); };
            [[nodiscard]] IClient& getClient() override { return m_client; };
            [[nodiscard]] KeyBoard::Key getEvents() override;
            [[nodiscard]] bool isRunning() override { return m_window.isOpen() && checkConnection(m_timeoutClock); };

            void init(const std::string &name, std::pair<const unsigned int,const unsigned int> resolution, unsigned int bitsPerPixel) override;
            void close() override { m_window.close(); getClient().disconnect(); };
            void render() override;

            static KeyBoard::Key getKeyboardEvent(const sf::Event &event);
            bool checkConnection(sf::Clock clock);

        private:

            sf::RenderWindow m_window;
            SFMLClient m_client;
            sf::Clock m_timeoutClock;

            static std::array<gui::KeyBoard::Key, sf::Keyboard::KeyCount> KEY_CODE_ARRAY;

    }; // class SFML

} // namespace sfml
