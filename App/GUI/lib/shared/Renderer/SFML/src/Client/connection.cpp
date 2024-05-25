/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** client.cpp
*/

#include "GUI/SFMLClient.hpp"

bool gui::SFMLClient::connect(const uint16_t port, const std::string &machineName)
{
    sf::Clock clk{};

    while(clk.getElapsedTime().asSeconds() < TIMEOUT) {
        if (m_socket.connect(machineName, port) == sf::Socket::Done)
            return true;
    }
    return false;
}

bool gui::SFMLClient::isConnected()
{
    sf::Packet packet;
    packet << "";
    return m_socket.send(packet) == sf::Socket::Done;
}
