/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Client.hpp
*/

#pragma once

#include <SFML/Network.hpp>

namespace gui {

    class Client {

        public:

            Client() = default;
            Client(Client const &to_copy) = delete;
            ~Client() = default;

            void connect(uint16_t port, const std::string &machineName);

        private:
            sf::TcpSocket m_socket{};
            sf::Socket::Status m_status{};
            sf::Packet m_packet{};

    }; // class Client

} // namespace gui
