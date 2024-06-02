/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Client.hpp
*/

#pragma once

#include <SFML/Network.hpp>

#include "GUI/Abstraction/IClient.hpp"
#include "GUI/Constant.hpp"

namespace gui {

    class SFMLClient : public IClient {

        public:

            ~SFMLClient() override = default;

            bool connect(uint16_t port, const std::string &machineName) override;
            void disconnect() override { m_socket.disconnect(); };

            bool sendCommand(const std::string &cmd) override;
            bool getResponse(const std::string &cmd) override;
            std::string getResponse() override;

            [[nodiscard]] bool isConnected() override;

        private:

            sf::TcpSocket m_socket;

    }; // class Client

} // namespace gui
