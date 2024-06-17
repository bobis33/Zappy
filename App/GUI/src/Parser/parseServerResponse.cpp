/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** parseServerResponse
*/

#include <iterator>
#include <sstream>

#include "GUI/Protocol.hpp"

gui::Player::Orientation gui::Parser::parseOrientation(const std::string &orientation)
{
    switch (std::stoi(orientation)) {
        case 1:
            return Player::Orientation::NORTH;
        case 2:
            return Player::Orientation::EAST;
        case 3:
            return Player::Orientation::SOUTH;
        case 4:
            return Player::Orientation::WEST;
        default:
            break;
    }
    throw std::runtime_error("Invalid orientation");
}

gui::Tile gui::Parser::parseTileContent(std::string &tileContent)
{
    tileContent.erase(
            std::remove(tileContent.begin(), tileContent.end(), '\0'),
            tileContent.end()
    );

    std::istringstream iss(tileContent);
    std::vector<unsigned int> values((std::istream_iterator<int>(iss)), std::istream_iterator<int>());
    if (values.size() != 9) {
        throw std::runtime_error("Invalid tile content");
    }
    return {
        {
            {Resource::Type::FOOD, values.at(2)},
            {Resource::Type::LINEMATE, values.at(3)},
            {Resource::Type::DERAUMERE, values.at(4)},
            {Resource::Type::SIBUR, values.at(5)},
            {Resource::Type::MENDIANE, values.at(6)},
            {Resource::Type::PHIRAS, values.at(7)},
            {Resource::Type::THYSTAME, values.at(8)}
        },
        {
            values.at(0),
            values.at(1)
        }
    };
}

gui::Egg gui::Parser::parseEggContent(const std::vector<std::string> &eggContent)
{
    if (eggContent.size() != 4) {
        throw std::runtime_error("Invalid egg content");
    }
    return {
        static_cast<unsigned int>(std::stoi(eggContent[0])),
        std::stoi(eggContent[1]),
        static_cast<unsigned int>(std::stoi(eggContent[2])),
        static_cast<unsigned int>(std::stoi(eggContent[3]))
    };
}

void gui::Parser::processData(const std::vector<std::string>& data, Gui &gui)
{
    for (const std::string& line : data) {
        auto command_val = Protocol::ProtocolMap.find(line.substr(0, 3));
        if (command_val != Protocol::ProtocolMap.end()) {
            if (line.substr(4, line.size()).empty()) {
                continue;
            }
            command_val->second(gui, line.substr(4, line.size()));
        }
    }
}

std::vector<std::string> gui::Parser::getData(const std::string &data)
{
    std::vector<std::string> tmp;
    std::string tmpData;
    std::stringstream ss(data);

    while (std::getline(ss, tmpData, '\n')) {
        tmp.push_back(tmpData);
    }
    return tmp;
}
