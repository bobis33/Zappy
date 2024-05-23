/*
** EPITECH PROJECT, 2024
** Zappy_gui
** File description:
** RunTimeException.hpp
*/

#pragma once

#include <string>

namespace gui {

    class RunTimeException : public std::exception
    {
        public:

            explicit RunTimeException(std::string msg) : m_msg{std::move(msg)} {};
            ~RunTimeException() override = default;

            RunTimeException(const RunTimeException &) = delete;
            RunTimeException &operator=(const RunTimeException &) = delete;
            RunTimeException(const RunTimeException &&) = delete;
            RunTimeException &operator=(const RunTimeException &&) = delete;

            [[nodiscard]] const char *what() const noexcept override { return m_msg.c_str(); };

        private:

            std::string m_msg{0};

    }; // class RunTimeException

} // namespace gui
