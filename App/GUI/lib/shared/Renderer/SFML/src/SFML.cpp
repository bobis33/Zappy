/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** SFML.cpp
*/

#include "GUI/SFML.hpp"
#include <iostream>

std::array<gui::KeyBoard::Key, sf::Keyboard::KeyCount> gui::SFML::KEY_CODE_ARRAY;

gui::KeyBoard::Key gui::SFML::getKeyboardEvent(const sf::Event &event)
{
    return event.key.code >= sf::Keyboard::KeyCount ? gui::KeyBoard::Key::NONE : KEY_CODE_ARRAY.at(static_cast<unsigned long>(event.key.code));
}

void gui::SFML::init(const std::string &name, std::pair<const unsigned int,const unsigned int> resolution, const unsigned int bitsPerPixel)
{
    std::fill_n(KEY_CODE_ARRAY.begin(), KEY_CODE_ARRAY.size(), KeyBoard::Key::NONE);
    KEY_CODE_ARRAY.at(sf::Keyboard::Escape) = KeyBoard::Key::CLOSE;
    KEY_CODE_ARRAY.at(sf::Keyboard::Enter) = KeyBoard::Key::KEY_ENTER;
    KEY_CODE_ARRAY.at(sf::Keyboard::Left) = KeyBoard::Key::KEY_LEFT;
    KEY_CODE_ARRAY.at(sf::Keyboard::Right) = KeyBoard::Key::KEY_RIGHT;
    KEY_CODE_ARRAY.at(sf::Keyboard::Up) = KeyBoard::Key::KEY_UP;
    KEY_CODE_ARRAY.at(sf::Keyboard::Down) = KeyBoard::Key::KEY_DOWN;
    KEY_CODE_ARRAY.at(sf::Keyboard::Space) = KeyBoard::Key::KEY_SPACE;

    m_window.create(sf::VideoMode(resolution.first, resolution.second, bitsPerPixel), name, sf::Style::Resize | sf::Style::Close);
    m_timeoutClock.restart();

    if (!t_tile.loadFromFile("assets/textures/forest_.png")) {
        throw std::runtime_error("Failed to load texture");
    }

    sf::IntRect textureRect(100, 85, 40, 40);
    s_tile.setTexture(t_tile);
    s_tile.setTextureRect(textureRect);

    if (!t_background.loadFromFile("assets/textures/background.jpg")) {
        throw std::runtime_error("Failed to load background texture");
    }

    s_background.setTexture(t_background);
    s_background.setScale(
        static_cast<float>(resolution.first) / t_background.getSize().x,
        static_cast<float>(resolution.second) / t_background.getSize().y
    );
}

bool gui::SFML::checkConnection(sf::Clock clock)
{
    if (!getClient().isConnected()) {
        clock.restart();
        while (clock.getElapsedTime().asSeconds() < TIMEOUT) {
            if (getClient().isConnected()) {
                return true;
            }
        }
        return false;
    }
    return true;
}

void gui::SFML::render(Map &tiles)
{
    m_window.clear({0, 0, 0, 0});
    m_window.draw(s_background);
    sf::Vector2u windowSize = m_window.getSize();

    float windowAspectRatio = static_cast<float>(windowSize.x) / windowSize.y;
    float tileAspectRatio = static_cast<float>(s_tile.getTextureRect().width) / s_tile.getTextureRect().height;

    float scaleX = static_cast<float>(windowSize.x) / (tiles.getWidth() * s_tile.getTextureRect().width);
    float scaleY = static_cast<float>(windowSize.y) / (tiles.getHeight() * s_tile.getTextureRect().height);

    if (windowAspectRatio > tileAspectRatio) {
        scaleX = scaleY;
    } else {
        scaleY = scaleX;
    }

    s_tile.setScale(scaleX, scaleY);

    for (auto& row : tiles.getTiles()) {
        for (auto& tile : row) {
            s_tile.setPosition(
                tile.getPosition().x * (s_tile.getGlobalBounds().width),
                tile.getPosition().y * (s_tile.getGlobalBounds().height)
            );
            m_window.draw(s_tile);
        }
    }
    m_window.display();
}
