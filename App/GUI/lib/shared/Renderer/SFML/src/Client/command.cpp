/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** command.cpp
*/

#include <array>

#include "GUI/SFMLClient.hpp"

std::string gui::SFMLClient::getResponse()
{
    bool isInIt = true;
    std::string string;
    std::array<char, MAX_OCTETS_READ> response{};
    std::size_t received = 0;
    std::vector<std::array<char, MAX_OCTETS_READ>> responseList;

    while (isInIt || (received == MAX_OCTETS_READ - 1 || received == MAX_OCTETS_READ)) {
        response.fill(0);
        if (m_socket.receive(&response, MAX_OCTETS_READ, received) == sf::Socket::Done) {
            responseList.push_back(response);
            isInIt = false;
        }
    }

    for (const auto& data : responseList) {
        string += std::string(data.data(), MAX_OCTETS_READ);
    }
    return string;
}

bool gui::SFMLClient::getResponse(const std::string& cmd)
{
    std::array<char, MAX_OCTETS_READ> data{};
    sf::Clock clk{};
    std::size_t received = 0;

    while (clk.getElapsedTime().asSeconds() < TIMEOUT) {
        if (m_socket.receive(&data, MAX_OCTETS_READ, received) == sf::Socket::Done && std::string(data.data(), received) == cmd){
            return true;
        }
    }

    return false;
}

bool gui::SFMLClient::sendCommand(const std::string& cmd)
{
    sf::Clock clk{};
    std::size_t total_sent = 0;
    std::size_t sent = 0;
    const std::size_t to_send = cmd.size();

    while (total_sent < to_send || clk.getElapsedTime().asSeconds() < TIMEOUT) {
        sent = 0;
        if (m_socket.send(cmd.c_str() + total_sent, to_send - total_sent, sent) == sf::Socket::Done) {
            return true;
        }
        total_sent += sent;
    }

    return false;
}
