/*
** EPITECH PROJECT, 2024
** Zappy | GUI
** File description:
** Constant.hpp
*/

/*
** @file Constant.hpp
** @brief Constants for the Zappy GUI
** @namespace gui
*/

#pragma once

#include <string_view>

namespace gui {

    static constexpr const int EPITECH_EXIT_SUCCESS = 0;
    static constexpr const int EPITECH_EXIT_ERROR = 84;

    static constexpr const std::string_view PLUGIN_RENDERER_SFML = "SFML";

    static constexpr const int MAX_OCTETS_READ = 4096;
    static constexpr const int TIMEOUT = 20;

    static constexpr const int MAX_PORT = 65535;

    static constexpr const unsigned int DEFAULT_FPS = 80;
    static constexpr const unsigned int DEFAULT_BITS_PER_PIXEL = 64;
    static constexpr const std::pair<const unsigned int, const unsigned int> DEFAULT_RESOLUTION {1920, 1080};
    static constexpr const std::string_view DEFAULT_NAME = "ZAPPY";
    static constexpr const int MAX_MAP_SIZE = 30;

} // namespace gui
