/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** client.cpp
*/

#include <cstdint>

#include "GUI/SFMLClient.hpp"
#include "GUI/RunTimeException.hpp"
#include "GUI/Constant.hpp"

bool gui::SFMLClient::connect(const uint16_t port, const std::string &machineName)
{
    sf::Clock clk{};

    while(clk.getElapsedTime().asSeconds() < TIMEOUT) {
        if (m_socket.connect(machineName, port) == sf::Socket::Done)
            return true;
    }
    return false;
}
