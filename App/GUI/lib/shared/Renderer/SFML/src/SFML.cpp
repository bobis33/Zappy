/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** SFML.cpp
*/

#include <SFML/Graphics.hpp>

#include "GUI/SFML.hpp"

static constexpr const int BIT_PER_PIXEL = 64;

static gui::KeyBoard::Key KEY_CODE_ARRAY[sf::Keyboard::KeyCount];

gui::KeyBoard::Key gui::SFML::getKeyboardEvent(const sf::Event &event)
{
    return event.key.code >= sf::Keyboard::KeyCount ? gui::KeyBoard::Key::NONE : KEY_CODE_ARRAY[event.key.code];
}

void gui::SFML::init(const std::pair<unsigned int, unsigned int> resolution, const std::string &name)
{
    std::fill_n(KEY_CODE_ARRAY, sf::Keyboard::KeyCount, KeyBoard::Key::NONE);
    KEY_CODE_ARRAY[sf::Keyboard::Escape] = KeyBoard::Key::KEY_ESCAPE;
    KEY_CODE_ARRAY[sf::Keyboard::Enter] = KeyBoard::Key::KEY_ENTER;
    KEY_CODE_ARRAY[sf::Keyboard::Left] = KeyBoard::Key::KEY_LEFT;
    KEY_CODE_ARRAY[sf::Keyboard::Right] = KeyBoard::Key::KEY_RIGHT;
    KEY_CODE_ARRAY[sf::Keyboard::Up] = KeyBoard::Key::KEY_UP;
    KEY_CODE_ARRAY[sf::Keyboard::Down] = KeyBoard::Key::KEY_DOWN;
    KEY_CODE_ARRAY[sf::Keyboard::Space] = KeyBoard::Key::KEY_SPACE;

    m_window.create(sf::VideoMode(resolution.first, resolution.second, BIT_PER_PIXEL), name, sf::Style::Resize | sf::Style::Close);
    m_timeoutClock.restart();
}

bool gui::SFML::checkConnection(sf::Clock clock)
{
    if (!getClient().isConnected()) {
        if (clock.getElapsedTime().asSeconds() > TIMEOUT) {
            return false;
        }
    } else {
        if (m_connectionReceived) {
            clock.restart();
        }
        m_connectionReceived = true;
    }

    return true;
}

void gui::SFML::render()
{
    if (!checkConnection(m_timeoutClock)) {
        m_isConnected = false;
    }
    m_window.display();
}
