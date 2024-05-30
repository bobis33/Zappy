/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** protocol
*/

#include "GUI/Protocol.hpp"

std::string gui::Protocol::getCommand(gui::ProtocolKey key)
{
    for (const auto &iterator : ProtocolMap) {
        if (iterator.second == key) {
            return iterator.first;
        }
    }
    return "";
}

gui::ProtocolKey gui::Protocol::getKey(const std::string &command)
{
    if (ProtocolMap.find(command) != ProtocolMap.end()) {
        return ProtocolMap.at(command);
    }

    return ProtocolKey::UNKNOWN;
}
