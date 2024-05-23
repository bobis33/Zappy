/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** IPlugin
*/

#pragma once

#include <string>

namespace gui {

    class IPlugin {

    public:

        virtual ~IPlugin() = default;

        [[nodiscard]] virtual std::string getPluginName() const = 0;

    }; // class IPlugin

} // namespace gui
