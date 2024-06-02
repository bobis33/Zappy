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
#include "GUI/Map/Map.hpp"

namespace gui {

    class Gui {

        public:

            enum class RendererMode {
                GAME,
                SETTINGS
            };

            explicit Gui(const Argument &args);
            ~Gui() = default;

            std::unique_ptr<IRenderer>& getRenderer() { return m_renderer; };

            void Run();

            static std::vector<std::string> getData(const std::string &data);
            void setMap(const Map &map) { m_map = map; };
            Map& getMap() { return m_map; };
            void initMap(const std::pair<unsigned, unsigned> &size);

        private:

            std::unique_ptr<IRenderer> m_renderer;
            std::vector<std::string> m_data;
            RendererMode m_mode{RendererMode::GAME};
            std::pair<int, int> m_mapSize{0, 0};
            Map m_map{30, 30, {}};

    }; // class Gui

} // namespace gui
