/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** SFML.cpp
*/

#include <iostream>

#include "GUI/SFML.hpp"

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

    if (!m_tileTexture.loadFromFile("assets/textures/forest.png")) {
        throw std::runtime_error("Failed to load texture");
    }

    sf::IntRect textureRect(100, 85, 40, 40);
    m_tileSprite.setTexture(m_tileTexture);
    m_tileSprite.setTextureRect(textureRect);

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

void gui::SFML::render(Map &map)
{
    m_window.clear({0, 0, 0, 0});
    sf::Vector2u windowSize = m_window.getSize();

    float windowAspectRatio = static_cast<float>(windowSize.x) / windowSize.y;
    float tileAspectRatio = static_cast<float>(m_tileSprite.getTextureRect().width) / m_tileSprite.getTextureRect().height;

    float scaleX = static_cast<float>(windowSize.x) / (map.getWidth() * m_tileSprite.getTextureRect().width);
    float scaleY = static_cast<float>(windowSize.y) / (map.getHeight() * m_tileSprite.getTextureRect().height);

    if (windowAspectRatio > tileAspectRatio) {
        scaleX = scaleY;
    } else {
        scaleY = scaleX;
    }

    m_tileSprite.setScale(scaleX, scaleY);

    for (auto& row : map.getTiles()) {
        for (auto& tile : row) {
            m_tileSprite.setPosition(
                tile.getPosition().x * (m_tileSprite.getGlobalBounds().width),
                tile.getPosition().y * (m_tileSprite.getGlobalBounds().height)
            );
            m_window.draw(m_tileSprite);
        }
    }
    m_window.display();
}
