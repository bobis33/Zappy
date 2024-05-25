/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** protocol
*/

#include "GUI/Protocol.hpp"

std::string gui::Protocol::getCommand(gui::ProtocolKey key)
{
    for (const auto &it : ProtocolMap) {
        if (it.second == key)
            return it.first;
    }
    return "";
}

gui::ProtocolKey gui::Protocol::getKey(const std::string &command)
{
    if (ProtocolMap.find(command) != ProtocolMap.end()) {
        return Map.at(command);
    }

    return ProtocolKey::UNKNOWN;
}
