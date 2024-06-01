/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** parser.cpp
*/

#include <getopt.h>
#include <regex>
#include <iostream>

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
                parseTileContent(tmpData);
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

gui::Inventory gui::Parser::parseTileContent(const std::string &tileContent)
{
    std::istringstream iss(tileContent);
    std::vector<unsigned int> values((std::istream_iterator<int>(iss)), std::istream_iterator<int>());

    if (values.size() != 9) {
        throw gui::RunTimeException("Invalid tile content format.");
    }

    std::cout << "Tile at (" << values.at(0) << ", " << values.at(1) << ") contains:" << '\n';

    return {
        {Resource::Type::FOOD, values.at(2)},
        {Resource::Type::LINEMATE, values.at(3)},
        {Resource::Type::DERAUMERE, values.at(4)},
        {Resource::Type::SIBUR, values.at(5)},
        {Resource::Type::MENDIANE, values.at(6)},
        {Resource::Type::PHIRAS, values.at(7)},
        {Resource::Type::THYSTAME, values.at(8)}
    };
}