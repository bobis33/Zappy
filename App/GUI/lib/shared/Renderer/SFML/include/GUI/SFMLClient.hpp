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

            bool sendCommand(const std::string &cmd) override;
            bool getResponse(const std::string &cmd) override;
            std::string getResponse() override;

        private:
            sf::TcpSocket m_socket{};
            sf::Socket::Status m_status{};
            sf::Packet m_packet{};

    }; // class Client

} // namespace gui
