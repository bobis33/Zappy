/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** SFML.cpp
*/

#include "GUI/SFML.hpp"
#include "GUI/Egg.hpp"
#include "GUI/Player.hpp"
#include "GUI/Parser.hpp"

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
    if (!texture.loadFromFile("assets/textures/Tile2.png")) {
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
    if (!texture.loadFromFile("assets/textures/side_screen/egg.png")) {
        throw std::runtime_error("Failed to load texture");
    }
    addTexture(texture, "egg");
    if (!texture.loadFromFile("assets/textures/idle.png")) {
        throw std::runtime_error("Failed to load texture");
    }
    addTexture(texture, "idle");
    if (!texture.loadFromFile("assets/textures/take.png")) {
        throw std::runtime_error("Failed to load texture");
    }
    addTexture(texture, "take");
    if (!texture.loadFromFile("assets/textures/Border1.png")) {
        throw std::runtime_error("Failed to load texture");
    }
    addTexture(texture, "border");
    if (!texture.loadFromFile("assets/textures/side_screen/egg.png")) {
        throw std::runtime_error("Failed to load texture");
    }
    addTexture(texture, "egg");
    if (!texture.loadFromFile("assets/textures/side_screen/food.png")) {
        throw std::runtime_error("Failed to load texture");
    }
    addTexture(texture, "food");
    if (!texture.loadFromFile("assets/textures/side_screen/stone1.png")) {
        throw std::runtime_error("Failed to load texture");
    }
    addTexture(texture, "linemate");
    if (!texture.loadFromFile("assets/textures/side_screen/stone2.png")) {
        throw std::runtime_error("Failed to load texture");
    }
    addTexture(texture, "deraumere");
    if (!texture.loadFromFile("assets/textures/side_screen/stone3.png")) {
        throw std::runtime_error("Failed to load texture");
    }
    addTexture(texture, "sibur");
    if (!texture.loadFromFile("assets/textures/side_screen/stone4.png")) {
        throw std::runtime_error("Failed to load texture");
    }
    addTexture(texture, "mendiane");
    if (!texture.loadFromFile("assets/textures/side_screen/stone5.png")) {
        throw std::runtime_error("Failed to load texture");
    }
    addTexture(texture, "phiras");
    if (!texture.loadFromFile("assets/textures/side_screen/stone6.png")) {
        throw std::runtime_error("Failed to load texture");
    }
    addTexture(texture, "thystame");
    sf::Sprite sprite;
    sprite.setTexture(getTextures().at(0).first);
    addSprite(sprite, "forest");
    sprite.setTexture(getTextures().at(1).first);
    addSprite(sprite, "food");
    sprite.setTexture(getTextures().at(2).first);
    addSprite(sprite, "linemate");
    sprite.setTexture(getTextures().at(3).first);
    addSprite(sprite, "deraumere");
    sprite.setTexture(getTextures().at(4).first);
    addSprite(sprite, "sibur");
    sprite.setTexture(getTextures().at(5).first);
    addSprite(sprite, "mendiane");
    sprite.setTexture(getTextures().at(6).first);
    addSprite(sprite, "phiras");
    sprite.setTexture(getTextures().at(7).first);
    addSprite(sprite, "thystame");
    sprite.setTexture(getTextures().at(8).first);
    addSprite(sprite, "egg");
    sprite.setTexture(getTextures().at(9).first);
    addSprite(sprite, "idle");
    sprite.setTexture(getTextures().at(10).first);
    addSprite(sprite, "take");
    sprite.setTexture(getTextures().at(11).first);
    addSprite(sprite, "border");
    sprite.setTexture(getTextures().at(12).first);
    addSprite(sprite, "food");
    sprite.setTexture(getTextures().at(13).first);
    addSprite(sprite, "linemate");
    sprite.setTexture(getTextures().at(14).first);
    addSprite(sprite, "deraumere");
    sprite.setTexture(getTextures().at(15).first);
    addSprite(sprite, "sibur");
    sprite.setTexture(getTextures().at(16).first);
    addSprite(sprite, "mendiane");
    sprite.setTexture(getTextures().at(17).first);
    addSprite(sprite, "phiras");
    sprite.setTexture(getTextures().at(18).first);
    addSprite(sprite, "thystame");
    sprite.setTexture(getTextures().at(19).first);
    addSprite(sprite, "egg");
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

void gui::SFML::render(Map &map, std::vector<Egg> &egg, std::vector<Player> &player)
{
    m_window.clear({0, 0, 0, 0});
    std::vector<float> spritesAspectRatio;
    sf::Vector2u windowSize = m_window.getSize();
    sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);
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

    float scaleFactor = (scaleX + scaleY) / 2.0f;

    bool mouseOnTile = false;
    for (auto& row : map.getTiles()) {
        for (auto& tile : row) {
            float tilePosX = static_cast<float>(tile.getPosition().y) * getSprites().at(0).first.getGlobalBounds().height;
            float tilePosY = static_cast<float>(tile.getPosition().x) * getSprites().at(0).first.getGlobalBounds().width;
            getSprites().at(0).first.setPosition(tilePosX, tilePosY);
            m_window.draw(getSprites().at(0).first);
            for (auto &egg : egg) {
                getSprites().at(8).first.setPosition(
                    static_cast<float>(egg.getY()) * getSprites().at(0).first.getGlobalBounds().height,
                    static_cast<float>(egg.getX()) * getSprites().at(0).first.getGlobalBounds().width);
                if (!egg.isDead())
                    m_window.draw(getSprites().at(8).first);
            }
            for (auto &player : player) {
                if (player.getAction() == Player::Action::NONE) {
                    getSprites().at(9).first.setPosition(
                        static_cast<float>(player.getPosition().x) * getSprites().at(0).first.getGlobalBounds().width,
                        static_cast<float>(player.getPosition().y) * getSprites().at(0).first.getGlobalBounds().height);
                    m_window.draw(getSprites().at(9).first);
                } else if (player.getAction() == Player::Action::TAKE) {
                    getSprites().at(10).first.setPosition(
                        static_cast<float>(player.getPosition().x) * getSprites().at(0).first.getGlobalBounds().width,
                        static_cast<float>(player.getPosition().y) * getSprites().at(0).first.getGlobalBounds().height);
                    m_window.draw(getSprites().at(10).first);
                }
            }

            if (mousePosition.x >= tilePosX && mousePosition.x < tilePosX + getSprites().at(0).first.getGlobalBounds().width &&
                mousePosition.y >= tilePosY && mousePosition.y < tilePosY + getSprites().at(0).first.getGlobalBounds().height) {

                mouseOnTile = true;

                getSprites().at(11).first.setPosition(tilePosX, tilePosY);
                const auto& resources = tile.getInventory().resources;
                float resourcePosX = static_cast<float>(map.getWidth() * getSprites().at(0).first.getGlobalBounds().width) + 20.0f;
                float resourcePosY = static_cast<float>(map.getHeight() * getSprites().at(0).first.getGlobalBounds().height) / 2.0f - 200.0f;

                for (size_t i = 0; i < resources.size(); i++) {
                    if (resources[i].quantity >= 0) {
                        sf::Text resourceText;
                        sf::Font someFont;
                        someFont.loadFromFile("assets/fonts/pixel.ttf");
                        resourceText.setFont(someFont);
                        resourceText.setString(std::to_string(resources[i].quantity) + "x ");
                        resourceText.setCharacterSize(24);
                        resourceText.setFillColor(sf::Color::White);
                        resourceText.setPosition(resourcePosX + 40.0f * scaleFactor, resourcePosY + 20.0f * scaleFactor);

                        m_window.draw(resourceText);
                        getSprites().at(i + 13).first.setPosition(resourcePosX + 55.0f * scaleFactor, resourcePosY + 15.0f * scaleFactor);
                        m_window.draw(getSprites().at(i + 13).first);

                        resourcePosY += 20.0f * scaleFactor;
                    }
                }
            }

            const auto& resources = tile.getInventory().resources;
            for (size_t i = 0; i < 7; i++) {
                if (resources[i].quantity > 0) {
                    getSprites().at(i + 1).first.setPosition(tilePosX, tilePosY);
                    m_window.draw(getSprites().at(i + 1).first);
                }
            }
        }
    }

    if (!mouseOnTile) {
        float titlePosX = static_cast<float>(map.getWidth() * getSprites().at(0).first.getGlobalBounds().width) + 130.0f;
        float titlePosY = static_cast<float>(map.getHeight() * getSprites().at(0).first.getGlobalBounds().height) / 2.0f - 50.0f;

        sf::Text titleText;
        sf::Font titleFont;
        titleFont.loadFromFile("assets/fonts/pixel.ttf");
        titleText.setFont(titleFont);
        titleText.setString("Zappy");
        titleText.setCharacterSize(static_cast<unsigned int>(30 * scaleFactor));
        titleText.setFillColor(sf::Color::White);
        titleText.setPosition(titlePosX, titlePosY);

        m_window.draw(titleText);
    }

    m_window.draw(getSprites().at(11).first);

    m_window.display();
}
