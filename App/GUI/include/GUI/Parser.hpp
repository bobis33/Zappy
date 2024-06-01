/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Parser
*/

#pragma once

#include "GUI/Argument.hpp"
#include "GUI/Gui.hpp"
#include "GUI/Inventory/Inventory.hpp"

namespace gui {

    class Parser {

        public:

            Parser() = default;
            ~Parser() = default;

            static Argument ParseArgs(int argc, char* const argv[]);

            static uint16_t ParsePort(const char* port);
            static std::string ParseMachineName(const char* machineName);

            static void processData(std::vector<std::string> data, Gui &gui);
            static Inventory parseTileContent(const std::string &tileContent);

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
