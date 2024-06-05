/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** parser.cpp
*/

#include <getopt.h>
#include <regex>

#include "GUI/Parser.hpp"
#include "GUI/Constant.hpp"

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

    return static_cast<uint16_t>(portInt);
}

gui::Argument gui::Parser::getOptions(const int argc, char* const argv[], const std::string &optString)
{
    uint16_t port = 0;
    std::string machineName;
    int optionChar = 0;
    while((optionChar = getopt(argc, argv, optString.c_str())) != -1) {
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
