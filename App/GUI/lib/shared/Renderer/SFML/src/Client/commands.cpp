/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** commands
*/

#include "GUI/SFMLClient.hpp"

std::string gui::SFMLClient::getResponse()
{
    char buff[4096] = {0};
    std::size_t size;
    sf::Clock clk{};

    while (clk.getElapsedTime().asSeconds() < 20) {
        if (m_socket.receive(&buff, 4096, size) == sf::Socket::Done) {
            return buff;
        }
    }

    return "";
}

bool gui::SFMLClient::getResponse(const std::string& cmd)
{
    char buff[4096] = {0};
    std::size_t size;
    sf::Clock clk{};

    while (clk.getElapsedTime().asSeconds() < 20) {
        if (m_socket.receive(&buff, 4096, size) == sf::Socket::Done && buff == cmd) {
            return true;
        }
    }

    return false;
}

bool gui::SFMLClient::sendCommand(const std::string& cmd)
{
    const std::size_t to_send = cmd.size();
    std::size_t total_sent = 0;
    std::size_t sent = 0;

    while (total_sent < to_send) {
        sent = 0;
        m_status = m_socket.send(cmd.c_str() + total_sent, to_send - total_sent, sent);
        if (m_status == sf::Socket::Error || m_status == sf::Socket::Disconnected) {
            return false;
        }
        total_sent += sent;
    }

    return true;
}
