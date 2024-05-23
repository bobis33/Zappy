/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** client.cpp
*/

#include <cstdint>

#include "GUI/Client.hpp"
#include "GUI/RunTimeException.hpp"

void gui::Client::connect(const uint16_t port, const std::string &machineName)
{
    m_socket.connect(machineName, port) != sf::Socket::Done ? throw RunTimeException("Connection failed") : void();
}
