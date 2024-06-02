/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** parser.cpp
*/

#include <getopt.h>
#include <regex>
#include <iostream>
#include <iterator>

#include "GUI/Parser.hpp"
#include "GUI/Constant.hpp"
#include "GUI/Protocol.hpp"

static constexpr const std::string_view HELP_MSG = "USAGE\n"
                                                   "    ./zappy_gui -p port -h machine\n"
                                                   "DESCRIPTION\n"
                                                   "    Zappy GUI\n";

std::string gui::Parser::parseMachineName(const char* machineName)
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

uint16_t gui::Parser::parsePort(const char* port)
{
    int portInt = std::stoi(port);

    if (portInt < 0 || portInt > MAX_PORT) {
        throw ParserException("Invalid port");
    }

    return static_cast<unsigned short int>(portInt);
}

gui::Argument gui::Parser::parseArgs(const int argc, char* const argv[])
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
                port = parsePort(optarg);
                break;
            case 'h':
                machineName = parseMachineName(optarg);
                break;
            default:
                throw ParserException("Invalid argument");
        }
    }

    return {port, machineName};
}

void gui::Parser::processData(const std::vector<std::string>& data, Gui &gui)
{
    std::string tmpData;
    for (const std::string &line : data) {
        const auto command_val = ProtocolMap.find(line.substr(0, 3));
        if (command_val != ProtocolMap.end()) {
            tmpData = line.substr(4, line.size());
            switch (command_val->second)
            {
            case ProtocolKey::MAP_SIZE:
                gui.initMap({std::stoi(tmpData.substr(0, tmpData.find(' '))),
                             std::stoi(tmpData.substr(tmpData.find(' ') + 1, tmpData.size()))});
                break;

            case ProtocolKey::TILE_CONTENT:
                gui.getMap().addTile(parseTileContent(tmpData));
                break;

            case ProtocolKey::MAP_CONTENT:
                break;

            case ProtocolKey::TEAMS_NAME:
                break;

            case ProtocolKey::PLAYER_CONNECTION:
                break;

            case ProtocolKey::PLAYER_POSITION:
                break;

            case ProtocolKey::PLAYER_LEVEL:
                break;

            case ProtocolKey::PLAYER_INVENTORY:
                break;

            case ProtocolKey::EXPULSION:
                break;

            case ProtocolKey::BROADCAST:
                break;

            case ProtocolKey::INCANTATION_START:
                break;

            case ProtocolKey::INCANTATION_END:
                break;

            case ProtocolKey::FORK:
                break;

            case ProtocolKey::RESOURCES_DROP:
                break;

            case ProtocolKey::RESOURCES_COLLECT:
                break;

            case ProtocolKey::PLAYER_DEATH:
                break;

            case ProtocolKey::EGG_LAID:
                break;

            case ProtocolKey::PLAYER_EGG_CONNECTION:
                break;

            case ProtocolKey::EGG_DEATH:
                break;

            case ProtocolKey::TIME_UNIT_REQUEST:
                break;

            case ProtocolKey::TIME_UNIT_MODIFICATION:
                break;

            case ProtocolKey::END_GAME:
                break;

            case ProtocolKey::MESSAGE:
                break;

            case ProtocolKey::UNKNOWN:
                break;

            case ProtocolKey::UNKNOWN_PARAMETER:
                break;

            case ProtocolKey::EGG_MATURE:
                break;

            default:
                break;
            }
        }
    }
}

gui::Tile gui::Parser::parseTileContent(const std::string &tileContent)
{
    std::istringstream iss(tileContent);
    std::vector<unsigned int> values((std::istream_iterator<int>(iss)), std::istream_iterator<int>());
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