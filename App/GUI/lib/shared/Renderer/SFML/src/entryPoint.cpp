/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** entryPoint.cpp
*/

#include <memory>

#include "GUI/SFML.hpp"

extern "C"
{
    std::unique_ptr<gui::IRenderer> entryPoint()
    {
        return std::make_unique<gui::SFML>();
    }
}
