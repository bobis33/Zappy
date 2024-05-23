/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** ARenderer
*/

#pragma once

#include "GUI/Abstraction/IRenderer.hpp"
#include "GUI/Constant.hpp"

namespace gui {

    class ARenderer : public IRenderer {

        public:

            void setName(const std::string& name) override { m_name = name; };
            void setResolution(const std::pair<unsigned int, unsigned int>& resolution) override { m_resolution = resolution; };
            void setFPS(const unsigned int FPS) override { m_FPS = FPS; };

            [[nodiscard]] const std::string& getName() const override { return m_name; };
            [[nodiscard]] const std::pair<unsigned int, unsigned int>& getResolution() const override { return m_resolution; };
            [[nodiscard]] const unsigned int& getFPS() const override { return m_FPS; };

        private:

            std::string m_name{DEFAULT_NAME.data()};
            std::pair<unsigned int, unsigned int> m_resolution{DEFAULT_RESOLUTION};
            unsigned int m_FPS{DEFAULT_FPS};

    }; // class ARenderer

} // namespace gui
