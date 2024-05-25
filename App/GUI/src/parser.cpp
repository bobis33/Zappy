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

static constexpr const std::string_view HELP_MSG = "USAGE\n"
                                                   "    ./zappy_gui -p port -h machine\n"
                                                   "DESCRIPTION\n"
                                                   "    Zappy GUI\n";

std::string gui::Parser::ParseMachineName(const char* machineName)
{
    std::string machineNameStr(machineName);
    const std::regex ip_regex(R"(^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$)");

    if (machineNameStr == "localhost") {
        return {"127.0.0.1"};
    }else if (machineNameStr.empty() || std::regex_match(machineNameStr, ip_regex)) {
        return machineNameStr;
    } else {
        throw ParserException("Invalid IP address format");
    }
}

uint16_t gui::Parser::ParsePort(const char* port)
{
    int portInt = std::stoi(port);

    if (portInt < 0 || portInt > 65535) {
        throw ParserException("Invalid port");
    }

    return static_cast<uint16_t>(portInt);
}

gui::Argument gui::Parser::ParseArgs(const int argc, char* const argv[])
{
    uint16_t port = 0;
    std::string machineName;
    int c;

    if (argc == 2 && std::string(argv[1]) == "-help") {
        std::cout << HELP_MSG;
        exit(EPITECH_EXIT_SUCCESS);
    }

    while((c = getopt(argc, argv, "p:h:")) != -1) {
        switch (c) {
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