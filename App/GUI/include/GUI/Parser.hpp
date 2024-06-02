/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Parser
*/

#pragma once

#include "GUI/Argument.hpp"
#include "GUI/Gui.hpp"
#include "GUI/Map/Tile.hpp"

namespace gui {

    class Parser {

        public:

            static Argument parseArgs(int argc, char* const argv[]);

            static uint16_t parsePort(const char* port);
            static std::string parseMachineName(const char* machineName);

            static void processData(const std::vector<std::string>& data, Gui &gui);
            static Tile parseTileContent(const std::string &tileContent);

            class ParserException : public std::exception
            {
                public:

                    explicit ParserException(std::string msg) : m_msg{std::move(msg)} {};
                    ~ParserException() override = default;

                    ParserException(const ParserException &) = delete;
                    ParserException &operator=(const ParserException &) = delete;
                    ParserException(const ParserException &&) = delete;
                    ParserException &operator=(const ParserException &&) = delete;

                    [[nodiscard]] const char *what() const noexcept override { return m_msg.c_str(); };

                private:

                    std::string m_msg{0};

            }; // class ParserException

    }; // class Parser

} // namespace gui
