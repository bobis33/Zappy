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

            static const std::unordered_map<std::string, std::function<void(gui::Gui&, std::string)>> ProtocolMap;

            [[nodiscard]] static std::vector<std::string> parseCommand(const std::string &data) {
                std::vector<std::string> dataVector;
                std::string tmp;
                for (const auto &c : data) {
                    if (c == '\n' || c == ' ' || c == '\0') {
                        dataVector.push_back(tmp);
                        tmp.clear();
                    } else {
                        tmp += c;
                    }
                }
                if (!tmp.empty())
                    dataVector.push_back(tmp);
                return dataVector;
            };

    }; // class Protocol

} // namespace gui
