/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Parser
*/

#pragma once

namespace gui {

    struct Arguments {
        const uint16_t m_port;
        const std::string m_machineName;

        Arguments(uint16_t port, std::string  machineName) : m_port{port}, m_machineName{std::move(machineName)} {};
    };

    class Parser {

        public:

            Parser() = default;
            ~Parser() = default;

            static Arguments ParseArgs(int argc, char* const argv[]);

            static uint16_t ParsePort(const char* port);
            static std::string ParseMachineName(const char* machineName);

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
