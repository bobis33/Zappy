/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Argument
*/

#pragma once

#include <string>
#include <cstdint>

namespace gui {

    class Argument {

        public:

            Argument(const uint16_t p, std::string h) : port(p), hostName(std::move(h)) {};
            ~Argument() = default;

            const uint16_t port;
            const std::string hostName;

    }; // class Argument

} // namespace gui
