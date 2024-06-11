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
    if (!texture.loadFromFile("assets/textures/resources/wine.png")) {
        throw std::runtime_error("Failed to load texture");
    }
    addTexture(texture, "food");
    if (!texture.loadFromFile("assets/textures/resources/stone_1.png")) {
        throw std::runtime_error("Failed to load texture");
    }
    addTexture(texture, "linemate");
    if (!texture.loadFromFile("assets/textures/resources/stone_2.png")) {
        throw std::runtime_error("Failed to load texture");
    }
    addTexture(texture, "deraumere");
    if (!texture.loadFromFile("assets/textures/resources/stone_3.png")) {
        throw std::runtime_error("Failed to load texture");
    }
    addTexture(texture, "sibur");
    if (!texture.loadFromFile("assets/textures/resources/stone_4.png")) {
        throw std::runtime_error("Failed to load texture");
    }
    addTexture(texture, "mendiane");
    if (!texture.loadFromFile("assets/textures/resources/stone_5.png")) {
        throw std::runtime_error("Failed to load texture");
    }
    addTexture(texture, "phiras");
    if (!texture.loadFromFile("assets/textures/resources/stone_6.png")) {
        throw std::runtime_error("Failed to load texture");
    }
    addTexture(texture, "thystame");
    sf::Sprite sprite;
    sf::IntRect textureRect(100, 85, 40, 40);
    sprite.setTexture(getTextures().at(0).first);
    sprite.setTextureRect(textureRect);
    addSprite(sprite, "forest");
    sprite.setTexture(getTextures().at(1).first);
    sprite.setTextureRect(sf::IntRect(0, 0, 10, 31));
    addSprite(sprite, "food");
    sprite.setTexture(getTextures().at(2).first);
    sprite.setTextureRect(sf::IntRect(0, 0, 18, 30));
    addSprite(sprite, "linemate");
    sprite.setTexture(getTextures().at(3).first);
    sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    addSprite(sprite, "deraumere");
    sprite.setTexture(getTextures().at(4).first);
    sprite.setTextureRect(sf::IntRect(0, 0, 30, 32));
    addSprite(sprite, "sibur");
    sprite.setTexture(getTextures().at(5).first);
    sprite.setTextureRect(sf::IntRect(0, 0, 32, 30));
    addSprite(sprite, "mendiane");
    sprite.setTexture(getTextures().at(6).first);
    sprite.setTextureRect(sf::IntRect(0, 0, 28, 30));
    addSprite(sprite, "phiras");
    sprite.setTexture(getTextures().at(7).first);
    sprite.setTextureRect(sf::IntRect(0, 0, 28, 30));
    addSprite(sprite, "thystame");
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
    std::vector<float> spritesAspectRatio;
    sf::Vector2u windowSize = m_window.getSize();
    float windowAspectRatio = static_cast<float>(windowSize.x) / static_cast<float>(windowSize.y);
    float scaleX = 0;
    float scaleY = 0;
    size_t i = 0;

    for (auto &sprite : getSprites()) {
        spritesAspectRatio.push_back(static_cast<float>(sprite.first.getTextureRect().width) / static_cast<float>(sprite.first.getTextureRect().height));
        scaleX = static_cast<float>(windowSize.x) / static_cast<float>(map.getWidth() * static_cast<unsigned int>(sprite.first.getTextureRect().width));
        scaleY = static_cast<float>(windowSize.y) / static_cast<float>(map.getHeight() * static_cast<unsigned int>(sprite.first.getTextureRect().height));
        windowAspectRatio > spritesAspectRatio.at(i) ? scaleX = scaleY : scaleY = scaleX;
        sprite.first.setScale(scaleX, scaleY);
        i++;
    }
    for (int i = 1; i < getSprites().size(); i++) {
        getSprites().at(i).first.setScale(0.8, 0.8); // Tmp -> change the scale to match with the density of the item
    }
    for (auto& row : map.getTiles()) {
        for (auto& tile : row) {
            getSprites().at(0).first.setPosition(                           // la map
                static_cast<float>(tile.getPosition().x) * (getSprites().at(0).first.getGlobalBounds().width),
                static_cast<float>(tile.getPosition().y) * (getSprites().at(0).first.getGlobalBounds().height)
            );
            getSprites().at(1).first.setPosition(                           // le pinard
                static_cast<float>(tile.getPosition().x) * (getSprites().at(0).first.getGlobalBounds().width) + 48,
                static_cast<float>(tile.getPosition().y) * (getSprites().at(0).first.getGlobalBounds().height) + 43
            );
            getSprites().at(2).first.setPosition(                           // le petit vert
                static_cast<float>(tile.getPosition().x) * (getSprites().at(0).first.getGlobalBounds().width) + 20,
                static_cast<float>(tile.getPosition().y) * (getSprites().at(0).first.getGlobalBounds().height) + 15
            );
            getSprites().at(3).first.setPosition(                           // le rubis
                static_cast<float>(tile.getPosition().x) * (getSprites().at(0).first.getGlobalBounds().width) + 40,
                static_cast<float>(tile.getPosition().y) * (getSprites().at(0).first.getGlobalBounds().height) + 15
            );
            getSprites().at(4).first.setPosition(                           // le gros vert
                static_cast<float>(tile.getPosition().x) * (getSprites().at(0).first.getGlobalBounds().width) + 70,
                static_cast<float>(tile.getPosition().y) * (getSprites().at(0).first.getGlobalBounds().height) + 15
            );
            getSprites().at(5).first.setPosition(                           // le diamant
                static_cast<float>(tile.getPosition().x) * (getSprites().at(0).first.getGlobalBounds().width) + 15,
                static_cast<float>(tile.getPosition().y) * (getSprites().at(0).first.getGlobalBounds().height) + 70
            );
            getSprites().at(6).first.setPosition(                           // l'ambre
                static_cast<float>(tile.getPosition().x) * (getSprites().at(0).first.getGlobalBounds().width) + 42,
                static_cast<float>(tile.getPosition().y) * (getSprites().at(0).first.getGlobalBounds().height) + 70
            );
            getSprites().at(7).first.setPosition(                           // l'amethyste
                static_cast<float>(tile.getPosition().x) * (getSprites().at(0).first.getGlobalBounds().width) + 70,
                static_cast<float>(tile.getPosition().y) * (getSprites().at(0).first.getGlobalBounds().height) + 70
            );
            for (const auto& sprite : getSprites()) {
                m_window.draw(sprite.first);
            }
        }
    }
    m_window.display();
}
