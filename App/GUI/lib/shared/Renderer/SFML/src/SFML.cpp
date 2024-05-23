/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** SFML.cpp
*/

#include <SFML/Graphics.hpp>

#include "GUI/SFML.hpp"

bool gui::SFML::checkConnection(sf::Clock clock, bool &connexionReceived)
{
    if (!getClient().isConnected()) {
        if (clock.getElapsedTime().asSeconds() > 30) {
            return false;
        }
    } else {
        if (connexionReceived) {
            clock.restart();
        }
        connexionReceived = true;
    }

    return true;
}

void gui::SFML::render()
{
    sf::Clock clock;
    bool connexionReceived = false;
    m_window.create(sf::VideoMode(getResolution().first, getResolution().second), getName());
    m_window.setFramerateLimit(getFPS());

    while (m_window.isOpen() && m_isConnected) {

        if (!checkConnection(clock, connexionReceived)) {
            m_isConnected = false;
            break;
        }
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
                getClient().disconnect();
                break;

            default:
                break;
        }
    }
}

