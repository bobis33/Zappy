/*
** EPITECH PROJECT, 2024
** GUI SFML
** File description:
** event.cpp
*/

#include "GUI/SFML.hpp"

gui::KeyBoard::Key gui::SFML::getEvents()
{
    sf::Event event{};

    while (m_window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                return KeyBoard::Key::CLOSE;
            case sf::Event::KeyPressed:
                return getKeyboardEvent(event);
            case sf::Event::Resized:
                m_window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
                break;

            default:
                break;
        }
    }

    return KeyBoard::Key::NONE;
}
