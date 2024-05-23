/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Client.hpp
*/

#pragma once

#include <SFML/Network.hpp>

#include "GUI/Abstraction/IClient.hpp"

namespace gui {

    class SFMLClient : public IClient {

        public:

            ~SFMLClient() override = default;

            void connect(uint16_t port, const std::string &machineName) override;
            void disconnect() override;

            bool sendCommand(const std::string &cmd) override;
            bool getResponse(const std::string &cmd) override;
            std::string getResponse() override;

            [[nodiscard]] bool isConnected() override { return m_socket.getRemoteAddress() != sf::IpAddress::None; };

        private:
            sf::TcpSocket m_socket{};
            sf::Packet m_packet{};

    }; // class Client

} // namespace gui
