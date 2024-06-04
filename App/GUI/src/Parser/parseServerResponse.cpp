/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** parseServerResponse
*/

#include <iterator>
#include <sstream>
#include <iostream>

#include "GUI/Protocol.hpp"

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

gui::Tile gui::Parser::parseTileContent(std::string &tileContent)
{
    for (char & index : tileContent) {
        if (index == 0) {
            index = ' ';
        }
    }
    std::istringstream iss(tileContent);
    std::vector<unsigned int> values((std::istream_iterator<int>(iss)), std::istream_iterator<int>())
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
