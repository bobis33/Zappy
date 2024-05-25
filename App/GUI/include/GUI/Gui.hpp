/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Gui
*/

#pragma once

#include <memory>

#include "GUI/Abstraction/IRenderer.hpp"
#include "GUI/Argument.hpp"

namespace gui {


    class Gui {

        public:

            explicit Gui(const Argument &args);
            ~Gui() = default;

            void Run();

            std::unique_ptr<IRenderer>& getRenderer() { return m_renderer; };

        private:

            std::unique_ptr<IRenderer> m_renderer;
            std::string m_data;

    }; // class Gui

} // namespace gui
