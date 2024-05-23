/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** SFML.cpp
*/

#include <SFML/Graphics.hpp>

#include "GUI/SFML.hpp"

void gui::SFML::render()
{
    m_window.create(sf::VideoMode(getResolution().first, getResolution().second), getName());

    while (m_window.isOpen()) {
        handleEvents();
        m_window.clear(sf::Color::Black);
        m_window.display();
    }
}

void gui::SFML::handleEvents()
{
    sf::Event event{};

    while (m_window.pollEvent(event)) {

        switch(event.type) {
            case sf::Event::Closed:
                m_window.close();
                break;

            default:
                break;
        }
    }
}

