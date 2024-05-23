/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Gui
*/

#pragma once

#include <memory>

#include "GUI/Parser.hpp"
#include "GUI/Abstraction/IRenderer.hpp"

namespace gui {


    class Gui {

        public:

            explicit Gui(const Arguments& args);
            ~Gui() = default;

            void Run();

        private:

            std::unique_ptr<IRenderer> m_renderer;

    }; // class Gui

} // namespace gui
