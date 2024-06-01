/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Protocol
*/

#pragma once

#include <unordered_map>
#include <string>

namespace gui {

    enum class ProtocolKey {
        COUNT,
        MAP_SIZE,
        TILE_CONTENT,
        MAP_CONTENT,
        TEAMS_NAME,
        PLAYER_CONNECTION,
        PLAYER_POSITION,
        PLAYER_LEVEL,
        PLAYER_INVENTORY,
        EXPULSION,
        BROADCAST,
        INCANTATION_START,
        INCANTATION_END,
        FORK,
        RESOURCES_DROP,
        RESOURCES_COLLECT,
        PLAYER_DEATH,
        EGG_LAID,
        PLAYER_EGG_CONNECTION,
        EGG_DEATH,
        TIME_UNIT_REQUEST,
        TIME_UNIT_MODIFICATION,
        END_GAME,
        MESSAGE,
        UNKNOWN,
        UNKNOWN_PARAMETER,
        EGG_MATURE,
    };

    const std::unordered_map<std::string, gui::ProtocolKey> ProtocolMap {
        {"msz", ProtocolKey::MAP_SIZE},
        {"bct", ProtocolKey::TILE_CONTENT},
        {"mct", ProtocolKey::MAP_CONTENT},
        {"tna", ProtocolKey::TEAMS_NAME},
        {"pnw", ProtocolKey::PLAYER_CONNECTION},
        {"ppo", ProtocolKey::PLAYER_POSITION},
        {"plv", ProtocolKey::PLAYER_LEVEL},
        {"pin", ProtocolKey::PLAYER_INVENTORY},
        {"pex", ProtocolKey::EXPULSION},
        {"pbc", ProtocolKey::BROADCAST},
        {"pic", ProtocolKey::INCANTATION_START},
        {"pie", ProtocolKey::INCANTATION_END},
        {"pfk", ProtocolKey::FORK},
        {"pdr", ProtocolKey::RESOURCES_DROP},
        {"pgt", ProtocolKey::RESOURCES_COLLECT},
        {"pdi", ProtocolKey::PLAYER_DEATH},
        {"enw", ProtocolKey::EGG_LAID},
        {"eht", ProtocolKey::EGG_MATURE},
        {"ebo", ProtocolKey::EGG_DEATH},
        {"pex", ProtocolKey::PLAYER_EGG_CONNECTION},
        {"sgt", ProtocolKey::TIME_UNIT_REQUEST},
        {"sst", ProtocolKey::TIME_UNIT_MODIFICATION},
        {"seg", ProtocolKey::END_GAME},
        {"smg", ProtocolKey::MESSAGE},
        {"suc", ProtocolKey::UNKNOWN},
        {"sbp", ProtocolKey::UNKNOWN_PARAMETER},
    };

    class Protocol {

        public:

            [[nodiscard]] static std::string getCommand(ProtocolKey key);
            [[nodiscard]] static ProtocolKey getKey(const std::string &command);

    }; // class Protocol

} // namespace gui
