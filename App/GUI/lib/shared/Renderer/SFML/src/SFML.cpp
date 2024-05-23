/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** SFML.cpp
*/

#include <SFML/Graphics.hpp>

#include "GUI/SFML.hpp"

void gui::SFML::connect(const uint16_t port, const std::string &machineName)
{
    m_client.connect(port, machineName);
}

void gui::SFML::render()
{
    sf::RenderWindow window(sf::VideoMode(getResolution().first, getResolution().second), getName());

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        window.display();
    }
}
