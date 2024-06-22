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
    if (!texture.loadFromFile("assets/textures/resources/egg.png")) {
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
    if (!texture.loadFromFile("assets/textures/side_screen/egg.png")) {
        throw std::runtime_error("Failed to load texture");
    }
    addTexture(texture, "egg");
    if (!texture.loadFromFile("assets/textures/idle.png")) {
        throw std::runtime_error("Failed to load texture");
    }
    addTexture(texture, "death");
    if (!texture.loadFromFile("assets/textures/move.png")) {
        throw std::runtime_error("Failed to load texture");
    }
    addTexture(texture, "move");
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
    sprite.setTexture(getTextures().at(20).first);
    addSprite(sprite, "death");
    sprite.setTexture(getTextures().at(21).first);
    addSprite(sprite, "move");
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

void gui::SFML::render(Map &map, std::vector<Egg> &eggs, std::vector<Player> &players)
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

            for (auto &egg : eggs) {
                getSprites().at(8).first.setPosition(
                    static_cast<float>(egg.getY()) * getSprites().at(0).first.getGlobalBounds().height,
                    static_cast<float>(egg.getX()) * getSprites().at(0).first.getGlobalBounds().width);
                if (!egg.isDead())
                    m_window.draw(getSprites().at(8).first);
            }
            for (auto &player : players) {
                if (player.getPosition().x != player.getLastPosition().x || player.getPosition().y != player.getLastPosition().y) {
                    if (player.getPosition().x > player.getLastPosition().x) {
                        player.setMoving(Player::Orientation::SOUTH);
                    } else if (player.getPosition().x < player.getLastPosition().x) {
                        player.setMoving(Player::Orientation::NORTH);
                        playerframe = 0;
                    } else if (player.getPosition().y > player.getLastPosition().y) {
                        player.setMoving(Player::Orientation::EAST);
                    } else if (player.getPosition().y < player.getLastPosition().y) {
                        player.setMoving(Player::Orientation::WEST);
                    }
                    player.setLastPosition(player.getPosition());
                }

                if (player.getMoving() == Player::Orientation::OUI) {
                    if (movingClock.getElapsedTime().asMilliseconds() > 10) {
                        if (player.getMoving() == Player::Orientation::NORTH) {
                            float playerPosX = static_cast<float>(player.getPosition().y) * getSprites().at(0).first.getGlobalBounds().height;
                            float playerPosY = static_cast<float>(player.getPosition().x) * getSprites().at(0).first.getGlobalBounds().width;
                            float playerPosXLast = static_cast<float>(player.getPosition().y) * getSprites().at(0).first.getGlobalBounds().height;
                            float playerPosYLast = static_cast<float>(player.getPosition().x + 1) * getSprites().at(0).first.getGlobalBounds().width;
                            float playerDrawPosX = playerPosXLast;
                            float playerDrawPosY = playerPosYLast - player.index_moving;
                            if (playerDrawPosY > playerPosY) {
                                player.index_moving = player.index_moving + 1;
                                getSprites().at(21).first.setPosition(playerDrawPosX, playerDrawPosY);
                            } else {
                                player.index_moving = 0;
                                player.setMoving(Player::Orientation::NONE);
                                playerframe = 0;
                            }
                        } else if (player.getMoving() == Player::Orientation::SOUTH) {
                            float playerPosX = static_cast<float>(player.getPosition().y) * getSprites().at(0).first.getGlobalBounds().height;
                            float playerPosY = static_cast<float>(player.getPosition().x) * getSprites().at(0).first.getGlobalBounds().width;
                            float playerPosXLast = static_cast<float>(player.getPosition().y) * getSprites().at(0).first.getGlobalBounds().height;
                            float playerPosYLast = static_cast<float>(player.getPosition().x - 1) * getSprites().at(0).first.getGlobalBounds().width;
                            float playerDrawPosX = playerPosXLast;
                            float playerDrawPosY = playerPosYLast + player.index_moving;
                            if (playerDrawPosY < playerPosY) {
                                player.index_moving = player.index_moving + 1;
                                getSprites().at(21).first.setPosition(playerDrawPosX, playerDrawPosY);
                            } else {
                                player.index_moving = 0;
                                player.setMoving(Player::Orientation::NONE);
                                playerframe = 0;
                            }
                        } else if (player.getMoving() == Player::Orientation::EAST) {
                            float playerPosX = static_cast<float>(player.getPosition().y) * getSprites().at(0).first.getGlobalBounds().height;
                            float playerPosY = static_cast<float>(player.getPosition().x) * getSprites().at(0).first.getGlobalBounds().width;
                            float playerPosXLast = static_cast<float>(player.getPosition().y - 1) * getSprites().at(0).first.getGlobalBounds().height;
                            float playerPosYLast = static_cast<float>(player.getPosition().x) * getSprites().at(0).first.getGlobalBounds().width;
                            float playerDrawPosX = playerPosXLast + player.index_moving;
                            float playerDrawPosY = playerPosYLast;
                            if (playerDrawPosX < playerPosX) {
                                player.index_moving = player.index_moving + 1;
                                getSprites().at(21).first.setPosition(playerDrawPosX, playerDrawPosY);
                            } else {
                                player.index_moving = 0;
                                player.setMoving(Player::Orientation::NONE);
                                playerframe = 0;
                            }
                        } else if (player.getMoving() == Player::Orientation::WEST) {
                            float playerPosX = static_cast<float>(player.getPosition().y) * getSprites().at(0).first.getGlobalBounds().height;
                            float playerPosY = static_cast<float>(player.getPosition().x) * getSprites().at(0).first.getGlobalBounds().width;
                            float playerPosXLast = static_cast<float>(player.getPosition().y + 1) * getSprites().at(0).first.getGlobalBounds().height;
                            float playerPosYLast = static_cast<float>(player.getPosition().x) * getSprites().at(0).first.getGlobalBounds().width;
                            float playerDrawPosX = playerPosXLast - player.index_moving;
                            float playerDrawPosY = playerPosYLast;
                            if (playerDrawPosX > playerPosX) {
                                player.index_moving = player.index_moving + 1;
                                getSprites().at(21).first.setPosition(playerDrawPosX, playerDrawPosY);
                            } else {
                                player.index_moving = 0;
                                player.setMoving(Player::Orientation::NONE);
                                playerframe = 0;
                            }
                        }
                        movingClock.restart();
                    }
                    m_window.draw(getSprites().at(21).first);
                } else {                
                    if (player.getAction() == Player::Action::NONE) {
                        getSprites().at(9).first.setPosition(
                            static_cast<float>(player.getPosition().y) * getSprites().at(0).first.getGlobalBounds().height,
                            static_cast<float>(player.getPosition().x) * getSprites().at(0).first.getGlobalBounds().width);
                        m_window.draw(getSprites().at(9).first);
                    } else if (player.getAction() == Player::Action::TAKE) {
                        getSprites().at(10).first.setPosition(
                            static_cast<float>(player.getPosition().y) * getSprites().at(0).first.getGlobalBounds().height,
                            static_cast<float>(player.getPosition().x) * getSprites().at(0).first.getGlobalBounds().width);
                        m_window.draw(getSprites().at(10).first);
                    } else if (player.getAction() == Player::Action::DEATH) {
                        getSprites().at(21).first.setPosition(
                            static_cast<float>(player.getPosition().y) * getSprites().at(0).first.getGlobalBounds().height,
                            static_cast<float>(player.getPosition().x) * getSprites().at(0).first.getGlobalBounds().width);
                        m_window.draw(getSprites().at(20).first);
                    }
                }
            }

            if (mousePosition.x >= tilePosX && mousePosition.x < tilePosX + getSprites().at(0).first.getGlobalBounds().width &&
                mousePosition.y >= tilePosY && mousePosition.y < tilePosY + getSprites().at(0).first.getGlobalBounds().height) {

                mouseOnTile = true;

                getSprites().at(11).first.setPosition(tilePosX, tilePosY);
                const auto& resources = tile.getInventory().resources;
                float resourcePosX = static_cast<float>(map.getWidth() * getSprites().at(0).first.getGlobalBounds().width);
                float resourcePosY = static_cast<float>(map.getHeight() / getSprites().at(0).first.getGlobalBounds().height) + 60.0f;

                sf::Text resourceTitle;
                sf::Font someFont;
                someFont.loadFromFile("assets/fonts/pixel.ttf");
                resourceTitle.setFont(someFont);
                resourceTitle.setString("Tile " + std::to_string(tile.getPosition().x) + " " + std::to_string(tile.getPosition().y));
                resourceTitle.setCharacterSize(24);
                resourceTitle.setFillColor(sf::Color::White);
                resourceTitle.setPosition(resourcePosX + (10.0f * scaleFactor), resourcePosY - 15.0f * scaleFactor);
                m_window.draw(resourceTitle);

                for (size_t i = 0; i < resources.size(); i++) {
                    if (resources[i].quantity >= 0) {
                        sf::Text resourceText;
                        sf::Font someFont;
                        someFont.loadFromFile("assets/fonts/pixel.ttf");
                        resourceText.setFont(someFont);
                        resourceText.setString(std::to_string(resources[i].quantity) + "x ");
                        resourceText.setCharacterSize(20);
                        resourceText.setFillColor(sf::Color::White);
                        resourceText.setPosition(resourcePosX + 40.0f * scaleFactor, resourcePosY + (10.0f * scaleFactor));
                        m_window.draw(resourceText);

                        resourceText.setString(getSprites().at(i + 12).second);
                        resourceText.setPosition(resourcePosX + 80.0f * scaleFactor, resourcePosY + (10.0f * scaleFactor));
                        m_window.draw(resourceText);

                        getSprites().at(i + 12).first.setPosition(resourcePosX + 60.0f * scaleFactor, resourcePosY + 5.0f * scaleFactor);
                        m_window.draw(getSprites().at(i + 12).first);

                        resourcePosY += 15.0f * scaleFactor;
                    }
                }

                for (auto &player : players) {
                    if (mousePosition.x >= static_cast<int>(player.getPosition().y * getSprites().at(0).first.getGlobalBounds().height) &&
                        mousePosition.x < static_cast<int>((player.getPosition().y + 1) * getSprites().at(0).first.getGlobalBounds().height) &&
                        mousePosition.y >= static_cast<int>(player.getPosition().x * getSprites().at(0).first.getGlobalBounds().width) &&
                        mousePosition.y < static_cast<int>((player.getPosition().x + 1) * getSprites().at(0).first.getGlobalBounds().width)) {

                        sf::Text playerText;
                        sf::Font someFont;
                        someFont.loadFromFile("assets/fonts/pixel.ttf");
                        playerText.setFont(someFont);
                        playerText.setString("Player " + std::to_string(player.getId()) + " - Level " + std::to_string(player.getLevel()) + " - " + player.getTeamName());
                        playerText.setCharacterSize(24);
                        playerText.setFillColor(sf::Color::White);
                        playerText.setPosition(resourcePosX + 10.0f * scaleFactor, resourcePosY + 20.0f * scaleFactor);
                        m_window.draw(playerText);

                        const auto& playerInventory = player.getInventory().resources;

                        // std::cout << players.at(0).getInventory().resources.size() << std::endl;

                        // float playerInventoryPosY = resourcePosY + 45.0f * scaleFactor;
                        // for (size_t j = 0; j < playerInventory.size(); j++) {
                        //     if (playerInventory[j].quantity >= 0) {
                        //         sf::Text playerInventoryText;
                        //         playerInventoryText.setFont(someFont);
                        //         playerInventoryText.setString(std::to_string(playerInventory[j].quantity) + "x ");
                        //         playerInventoryText.setCharacterSize(20);
                        //         playerInventoryText.setFillColor(sf::Color::White);
                        //         playerInventoryText.setPosition(resourcePosX + 40.0f * scaleFactor, playerInventoryPosY + (10.0f * scaleFactor));
                        //         m_window.draw(playerInventoryText);

                        //         playerInventoryText.setString(getSprites().at(j + 12).second);
                        //         playerInventoryText.setPosition(resourcePosX + 80.0f * scaleFactor, playerInventoryPosY + (10.0f * scaleFactor));
                        //         m_window.draw(playerInventoryText);

                        //         getSprites().at(j + 12).first.setPosition(resourcePosX + 60.0f * scaleFactor, playerInventoryPosY + 5.0f * scaleFactor);
                        //         m_window.draw(getSprites().at(j + 12).first);

                        //         playerInventoryPosY += 15.0f * scaleFactor;
                        //     }
                        // }
                    }
                }

                for (const auto &egg : eggs) {
                    if (mousePosition.x >= static_cast<int>(egg.getY() * getSprites().at(0).first.getGlobalBounds().height) &&
                        mousePosition.x < static_cast<int>((egg.getY() + 1) * getSprites().at(0).first.getGlobalBounds().height) &&
                        mousePosition.y >= static_cast<int>(egg.getX() * getSprites().at(0).first.getGlobalBounds().width) &&
                        mousePosition.y < static_cast<int>((egg.getX() + 1) * getSprites().at(0).first.getGlobalBounds().width)) {

                        getSprites().at(19).first.setPosition(resourcePosX + 45.0f * scaleFactor, resourcePosY + 9.0f * scaleFactor);
                        m_window.draw(getSprites().at(19).first);
                    }
                }
            }

            const auto& resources = tile.getInventory().resources;
            for (size_t inv = 0; inv < 7; inv++) {
                if (resources[inv].quantity > 0) {
                    getSprites().at(inv + 1).first.setPosition(tilePosX, tilePosY);
                    m_window.draw(getSprites().at(inv + 1).first);
                }
            }
        }
    }
    //draw border
    if (mouseOnTile) {
        m_window.draw(getSprites().at(11).first);
    }

    for (auto& player : players) {
        if (playerClock.getElapsedTime().asSeconds() > 0.08) {
            if (player.getAction() != player.getLastAction() && player.getAction() != Player::Action::NONE) {
                player.player_frame = 1;
                player.setLastAction(player.getAction());
            }
            player.player_frame++;
            if (player.player_frame > 4) {
                player.player_frame = 0;
                player.setAction(Player::Action::NONE);
            }
            playerClock.restart();
        }
        sf::IntRect playerRect(player.player_frame * 32, 0, 32, 32);
        getSprites().at(9).first.setTextureRect(playerRect);
        getSprites().at(10).first.setTextureRect(playerRect);
        getSprites().at(20).first.setTextureRect(playerRect);
        getSprites().at(21).first.setTextureRect(playerRect);
    }

    if (!mouseOnTile) {
        float titlePosX = static_cast<float>(static_cast<float>(map.getWidth()) * getSprites().at(0).first.getGlobalBounds().width) + 130.0f;
        float titlePosY = static_cast<float>(static_cast<float>(map.getHeight()) * getSprites().at(0).first.getGlobalBounds().height) / 2.0f - 50.0f;

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

    m_window.display();
}
