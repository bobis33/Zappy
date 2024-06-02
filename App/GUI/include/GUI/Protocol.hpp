/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Protocol
*/

#pragma once

#include <unordered_map>
#include <functional>

#include "GUI/Parser.hpp"

namespace gui {

    class Protocol {

        public:

            static const std::unordered_map<std::string, std::function<void(gui::Gui&, const std::string&)>> ProtocolMap;

    }; // class Protocol

} // namespace gui
