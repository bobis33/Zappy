/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** command.cpp
*/

#include "GUI/SFMLClient.hpp"

std::string gui::SFMLClient::getResponse()
{
    char data[MAX_OCTETS_READ] = {0};
    std::size_t size;
    sf::Clock clk{};

    while (clk.getElapsedTime().asSeconds() < TIMEOUT) {
        if (m_socket.receive(&data, MAX_OCTETS_READ, size) == sf::Socket::Done) {
            return data;
        }
    }

    return "";
}

bool gui::SFMLClient::getResponse(const std::string& cmd)
{
    char data[MAX_OCTETS_READ] = {0};
    std::size_t received;
    sf::Clock clk{};

    while (clk.getElapsedTime().asSeconds() < TIMEOUT) {
        if (m_socket.receive(&data, MAX_OCTETS_READ, received) == sf::Socket::Done && data == cmd) {
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
    sf::Clock clk{};

    while (total_sent < to_send || clk.getElapsedTime().asSeconds() < TIMEOUT) {
        sent = 0;
        if (m_socket.send(cmd.c_str() + total_sent, to_send - total_sent, sent) == sf::Socket::Done) {
            return true;
        }
        total_sent += sent;
    }

    return false;
}
