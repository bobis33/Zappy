/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Gui
*/

#pragma once

#include <memory>
#include <vector>

#include "GUI/Abstraction/IRenderer.hpp"
#include "GUI/Argument.hpp"

namespace gui {

    class Gui {

        public:

            explicit Gui(const Argument &args);
            ~Gui() = default;

            std::unique_ptr<IRenderer>& getRenderer() { return m_renderer; };

            void Run();

            static std::vector<std::string> getData(const std::string &data);

        private:

            std::unique_ptr<IRenderer> m_renderer;
            std::vector<std::string> m_data;

    }; // class Gui

} // namespace gui
