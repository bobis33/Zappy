/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** SFML.cpp
*/

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

    sf::Texture texture;
    if (!texture.loadFromFile("assets/textures/forest.png")) {
        throw std::runtime_error("Failed to load texture");
    }
    addTexture(texture, "forest");
    sf::Sprite sprite;
    sf::IntRect textureRect(100, 85, 40, 40);
    sprite.setTexture(getTextures().at(0).first);
    sprite.setTextureRect(textureRect);
    addSprite(sprite, "forest");
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

    float windowAspectRatio = static_cast<float>(windowSize.x) / static_cast<float>(windowSize.y);
    float spriteAspectRatio = static_cast<float>(getSprites().at(0).first.getTextureRect().width) / static_cast<float>(getSprites().at(0).first.getTextureRect().height);
    float scaleX = static_cast<float>(windowSize.x) / static_cast<float>(map.getWidth() * static_cast<unsigned int>(getSprites().at(0).first.getTextureRect().width));
    float scaleY = static_cast<float>(windowSize.y) / static_cast<float>(map.getHeight() * static_cast<unsigned int>(getSprites().at(0).first.getTextureRect().height));

    windowAspectRatio > spriteAspectRatio ? scaleX = scaleY : scaleY = scaleX;
    getSprites().at(0).first.setScale(scaleX, scaleY);

    for (auto& row : map.getTiles()) {
        for (auto& tile : row) {
            getSprites().at(0).first.setPosition(
                static_cast<float>(tile.getPosition().x) * (getSprites().at(0).first.getGlobalBounds().width),
                static_cast<float>(tile.getPosition().y) * (getSprites().at(0).first.getGlobalBounds().height)
            );
            m_window.draw(getSprites().at(0).first);
        }
    }
    m_window.display();
}
