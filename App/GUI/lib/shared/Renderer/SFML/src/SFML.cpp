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

    std::vector<std::pair<std::string, std::string>> texturePaths = {
        {"forest", "assets/textures/Tile2.png"},
        {"food", "assets/textures/resources/wine.png"},
        {"linemate", "assets/textures/resources/stone_1.png"},
        {"deraumere", "assets/textures/resources/stone_2.png"},
        {"sibur", "assets/textures/resources/stone_3.png"},
        {"mendiane", "assets/textures/resources/stone_4.png"},
        {"phiras", "assets/textures/resources/stone_5.png"},
        {"thystame", "assets/textures/resources/stone_6.png"},
        {"egg", "assets/textures/resources/egg.png"},
        {"idle", "assets/textures/idle.png"},
        {"take", "assets/textures/take.png"},
        {"border", "assets/textures/Border1.png"},
        {"food", "assets/textures/side_screen/food.png"},
        {"linemate", "assets/textures/side_screen/stone1.png"},
        {"deraumere", "assets/textures/side_screen/stone2.png"},
        {"sibur", "assets/textures/side_screen/stone3.png"},
        {"mendiane", "assets/textures/side_screen/stone4.png"},
        {"phiras", "assets/textures/side_screen/stone5.png"},
        {"thystame", "assets/textures/side_screen/stone6.png"},
        {"egg", "assets/textures/side_screen/egg.png"},
        {"death", "assets/textures/idle.png"},
        {"move", "assets/textures/move.png"}
    };

    sf::Texture texture;
    for (const auto& texturePath : texturePaths) {
        if (!texture.loadFromFile(texturePath.second)) {
            throw std::runtime_error("Failed to load texture");
        }
        addTexture(texture, texturePath.first);
    }
    std::vector<std::string> spritesNames = {
        "forest", "food", "linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame", "egg", "idle",
        "take", "border", "food", "linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame", "egg", "death", "move"
    };

    sf::Sprite sprite;
    for (size_t i = 0; i < spritesNames.size(); ++i) {
        sprite.setTexture(getTextures().at(i).first);
        addSprite(sprite, spritesNames[i]);
    }
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

void gui::SFML::render(Map &map, std::vector<Egg> &eggs, std::vector<Player> &players, std::vector<std::string> &teams, bool animations)
{
    m_window.clear({0, 0, 0, 0});
    std::vector<float> spritesAspectRatio;
    const sf::Vector2u minSize = {1280, 720};
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
                    } else if (player.getPosition().y > player.getLastPosition().y) {
                        player.setMoving(Player::Orientation::EAST);
                    } else if (player.getPosition().y < player.getLastPosition().y) {
                        player.setMoving(Player::Orientation::WEST);
                    }
                    player.setLastPosition(player.getPosition());
                }
                if (player.getMoving() != Player::Orientation::NONE && animations == true) {
                    if (player.moving_clock.getElapsedTime().asMilliseconds() > 5) {
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
                            }
                        }
                        player.moving_clock.restart();
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
                        resourceText.setPosition(resourcePosX + 50.0f, resourcePosY + 35.0f);
                        m_window.draw(resourceText);

                        resourceText.setString(getSprites().at(i + 12).second);
                        resourceText.setPosition(resourcePosX + 150.0f, resourcePosY + 35.0f);
                        m_window.draw(resourceText);

                        getSprites().at(i + 12).first.setPosition(resourcePosX + 100.0f, resourcePosY + 15.0f);
                        m_window.draw(getSprites().at(i + 12).first);

                        resourcePosY += 35.0f;
                    }
                }

                for (auto &player : players) {
                    if (mousePosition.x >= static_cast<int>(player.getPosition().y * getSprites().at(0).first.getGlobalBounds().height) &&
                        mousePosition.x < static_cast<int>((player.getPosition().y + 1) * getSprites().at(0).first.getGlobalBounds().height) &&
                        mousePosition.y >= static_cast<int>(player.getPosition().x * getSprites().at(0).first.getGlobalBounds().width) &&
                        mousePosition.y < static_cast<int>((player.getPosition().x + 1) * getSprites().at(0).first.getGlobalBounds().width)) {

                        sf::Text playerText;
                        playerText.setFont(someFont);
                        playerText.setString("Player " + std::to_string(player.getId()) + " - Level " + std::to_string(player.getLevel()) + " - " + player.getTeamName());
                        playerText.setCharacterSize(24);
                        playerText.setFillColor(sf::Color::White);
                        playerText.setPosition(resourcePosX + 10.0f * scaleFactor, resourcePosY + 20.0f * scaleFactor);
                        m_window.draw(playerText);
                        if (player.getAction() == Player::Action::NONE) {
                            getSprites().at(9).first.setPosition(resourcePosX + 150.0f * scaleFactor, resourcePosY + 30.0f * scaleFactor);
                            m_window.draw(getSprites().at(9).first);
                        } else if (player.getAction() == Player::Action::TAKE) {
                            getSprites().at(10).first.setPosition(resourcePosX + 150.0f * scaleFactor, resourcePosY + 30.0f * scaleFactor);
                            m_window.draw(getSprites().at(10).first);
                        } else if (player.getAction() == Player::Action::DEATH) {
                            getSprites().at(21).first.setPosition(resourcePosX + 150.0f * scaleFactor, resourcePosY + 30.0f * scaleFactor);
                            m_window.draw(getSprites().at(20).first);
                        } else if (player.getAction() == Player::Action::MOVE) {
                            getSprites().at(21).first.setPosition(resourcePosX + 150.0f * scaleFactor, resourcePosY + 30.0f * scaleFactor);
                            m_window.draw(getSprites().at(21).first);
                        }

                        const auto& playerInventory = player.getInventory().resources;

                        float playerInventoryPosY = resourcePosY + 45.0f * scaleFactor;
                        for (size_t j = 0; j < playerInventory.size(); j++) {
                            if (playerInventory[j].quantity >= 0) {
                                sf::Text playerInventoryText;
                                playerInventoryText.setFont(someFont);
                                playerInventoryText.setString(std::to_string(playerInventory[j].quantity) + "x ");
                                playerInventoryText.setCharacterSize(20);
                                playerInventoryText.setFillColor(sf::Color::White);
                                playerInventoryText.setPosition(resourcePosX + 40.0f * scaleFactor, playerInventoryPosY + (10.0f * scaleFactor));
                                m_window.draw(playerInventoryText);

                                getSprites().at(j + 12).first.setPosition(resourcePosX + 60.0f * scaleFactor, playerInventoryPosY + 5.0f * scaleFactor);
                                m_window.draw(getSprites().at(j + 12).first);

                                playerInventoryPosY += 15.0f * scaleFactor;
                            }
                        }
                    }
                }

                for (const auto &egg : eggs) {
                    if (mousePosition.x >= static_cast<int>(egg.getY() * getSprites().at(0).first.getGlobalBounds().height) &&
                        mousePosition.x < static_cast<int>((egg.getY() + 1) * getSprites().at(0).first.getGlobalBounds().height) &&
                        mousePosition.y >= static_cast<int>(egg.getX() * getSprites().at(0).first.getGlobalBounds().width) &&
                        mousePosition.y < static_cast<int>((egg.getX() + 1) * getSprites().at(0).first.getGlobalBounds().width)) {

                        getSprites().at(19).first.setPosition(resourcePosX + 150.0f * scaleFactor, resourcePosY - 10.0f * scaleFactor);
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

    //for (auto& player : players) {
    //    std::cout << "Player " << player.getId() << std::endl;
    //    if (playerClock.getElapsedTime().asSeconds() > 0.08) {
    //        //if (player.getAction() != player.getLastAction() && player.getAction() != Player::Action::NONE) {
    //        //    player.player_frame = 1;
    //        //    player.setLastAction(player.getAction());
    //        //}
    //        player.player_frame++;
    //        std::cout << "Player frame " << player.player_frame << std::endl;
    //        if (player.player_frame > 4) {
    //            player.player_frame = 0;
    //            player.setAction(Player::Action::NONE);
    //        }
    //        playerClock.restart();
    //    }
    //    sf::IntRect playerRect(player.player_frame * 32, 0, 32, 32);
    //    getSprites().at(9).first.setTextureRect(playerRect);
    //    getSprites().at(10).first.setTextureRect(playerRect);
    //    getSprites().at(20).first.setTextureRect(playerRect);
    //    getSprites().at(21).first.setTextureRect(playerRect);
    //}

    for (auto& player : players) {
        if (player.player_clock.getElapsedTime().asMilliseconds() > 80) {
            if (player.getAction() != player.getLastAction() && player.getAction() != Player::Action::NONE) {
                player.player_frame = 0;
                player.setLastAction(player.getAction());
            }
            player.player_frame++;
            if (player.player_frame > 4) {
                player.player_frame = 0;
                player.setAction(Player::Action::NONE);
            }
            player.player_clock.restart();
        }
    }

    for (auto& player : players) {
        sf::IntRect playerRect(player.player_frame * 32, 0, 32, 32);
        getSprites().at(9).first.setTextureRect(playerRect);
        getSprites().at(10).first.setTextureRect(playerRect);
        getSprites().at(20).first.setTextureRect(playerRect);
        getSprites().at(21).first.setTextureRect(playerRect);        
    }

    if (!mouseOnTile) {
        float titlePosX = static_cast<float>(static_cast<float>(map.getWidth()) * getSprites().at(0).first.getGlobalBounds().width) + 160.0f;
        float titlePosY = static_cast<float>(static_cast<float>(map.getHeight()) * getSprites().at(0).first.getGlobalBounds().height) - 1000.0f;

        sf::Text noMouseOnTile;
        sf::Font titleFont;
        titleFont.loadFromFile("assets/fonts/pixel.ttf");
        noMouseOnTile.setFont(titleFont);
        noMouseOnTile.setString("Zappy");
        noMouseOnTile.setCharacterSize(100);
        noMouseOnTile.setFillColor(sf::Color::White);
        noMouseOnTile.setPosition(titlePosX, titlePosY);
        m_window.draw(noMouseOnTile);

        noMouseOnTile.setString("TeamNames");
        noMouseOnTile.setCharacterSize(24);
        noMouseOnTile.setPosition(titlePosX - 100.0f, titlePosY + 150.0f);
        m_window.draw(noMouseOnTile);

        float teamPosY = static_cast<float>(static_cast<float>(map.getHeight()) * getSprites().at(0).first.getGlobalBounds().height) / 4.0f;

        titlePosY = teamPosY;
        for (const auto &team : teams) {
            noMouseOnTile.setString(team + " :");
            noMouseOnTile.setCharacterSize(20);
            noMouseOnTile.setPosition(titlePosX - 90.0f, titlePosY);
            m_window.draw(noMouseOnTile);
            titlePosY += 30.0f;

            std::string playersText;
            for (const auto &player : players) {
                if (player.getTeamName() == team)
                    playersText += std::to_string(player.getId()) + ", ";
            }

            if (!playersText.empty()) {
                playersText.pop_back();
                playersText.pop_back();

                noMouseOnTile.setString("Players " + playersText);
                noMouseOnTile.setCharacterSize(20);
                noMouseOnTile.setPosition(titlePosX, titlePosY);
                m_window.draw(noMouseOnTile);
                titlePosY += 50.0f;
            }
        }
    }

    m_window.display();
}

