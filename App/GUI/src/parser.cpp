/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** parser.cpp
*/

#include <getopt.h>
#include <regex>
#include <iostream>
#include <sstream>
#include <iterator>

#include "GUI/Parser.hpp"
#include "GUI/Constant.hpp"
#include "GUI/Protocol.hpp"

static constexpr const std::string_view HELP_MSG = "USAGE\n"
                                                   "    ./zappy_gui -p port -h machine\n"
                                                   "DESCRIPTION\n"
                                                   "    Zappy GUI\n";

std::string gui::Parser::ParseMachineName(const char* machineName)
{
    std::string machineNameStr(machineName);
    const std::regex ip_regex(R"(^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$)");

    if (machineNameStr == "localhost") {
        return "127.0.0.1";
    } if (machineNameStr.empty() || std::regex_match(machineNameStr, ip_regex)) {
        return machineNameStr;
    }

    throw ParserException("Invalid IP address format");
}

uint16_t gui::Parser::ParsePort(const char* port)
{
    int portInt = std::stoi(port);

    if (portInt < 0 || portInt > MAX_PORT) {
        throw ParserException("Invalid port");
    }

    return static_cast<unsigned short int>(portInt);
}

gui::Argument gui::Parser::ParseArgs(const int argc, char* const argv[])
{
    uint16_t port = 0;
    int optionChar = 0;
    std::string machineName;

    if (argc == 2 && std::string(argv[1]) == "-help") {
        std::cout << HELP_MSG;
        exit(EPITECH_EXIT_SUCCESS);
    }

    while((optionChar = getopt(argc, argv, "p:h:")) != -1) {
        switch (optionChar) {
            case 'p':
                port = ParsePort(optarg);
                break;
            case 'h':
                machineName = ParseMachineName(optarg);
                break;
            default:
                throw ParserException("Invalid argument");
        }
    }

    return {port, machineName};
}

void gui::Parser::processData(std::vector<std::string> data, Gui &gui)
{
    std::string command;
    std::string tmpData;
    for (const std::string &line : data) {
        command = line.substr(0, 3);
        const auto command_val = ProtocolMap.find(command);
        if (command_val != ProtocolMap.end()) {
            switch (command_val->second)
            {
            case ProtocolKey::MAP_SIZE:
                tmpData = line.substr(4, line.size());
                break;
            case ProtocolKey::TIME_UNIT_REQUEST:
                tmpData = line.substr(4, line.size());
                break;
            case ProtocolKey::TILE_CONTENT:
                tmpData = line.substr(4, line.size());
                break;
            case ProtocolKey::MAP_CONTENT:
                tmpData = line.substr(4, line.size());
                break;
            case ProtocolKey::TEAMS_NAME:
                tmpData = line.substr(4, line.size());
                break;
            case ProtocolKey::EGG_LAID:
                tmpData = line.substr(4, line.size());
                break;
            default:
                break;
            }
        }
    }
}

gui::Inventory gui::Parser::parseTileContent(std::string tileContent)
{
    std::istringstream iss(tileContent);
    std::vector<int> values((std::istream_iterator<int>(iss)), std::istream_iterator<int>());

    if (values.size() != 9) {
        throw gui::RunTimeException("Invalid tile content format.");
    }

    int x = values[0];
    int y = values[1];

    std::cout << "Tile at (" << x << ", " << y << ") contains:" << std::endl;

    Resource food(gui::Resource::Type::FOOD, static_cast<unsigned int>(values[2]));
    Resource linemate(gui::Resource::Type::LINEMATE, static_cast<unsigned int>(values[3]));
    Resource deraumere(gui::Resource::Type::DERAUMERE, static_cast<unsigned int>(values[4]));
    Resource sibur(gui::Resource::Type::SIBUR, static_cast<unsigned int>(values[5]));
    Resource mendiane(gui::Resource::Type::MENDIANE, static_cast<unsigned int>(values[6]));
    Resource phiras(gui::Resource::Type::PHIRAS, static_cast<unsigned int>(values[7]));
    Resource thystame(gui::Resource::Type::THYSTAME, static_cast<unsigned int>(values[8]));

    return gui::Inventory(food, linemate, deraumere, sibur, mendiane, phiras, thystame);
}