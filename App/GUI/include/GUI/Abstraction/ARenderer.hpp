/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** ARenderer
*/

#pragma once

#include "GUI/Abstraction/IRenderer.hpp"

namespace gui {

    class ARenderer : public IRenderer {

        public:

            void setName(const std::string& name) override { m_name = name; };
            void setResolution(const std::pair<unsigned int, unsigned int>& resolution) override { m_resolution = resolution; };
            void setFramerate(const unsigned int framerate) override { m_framerate = framerate; };

            [[nodiscard]] const std::string& getName() const override { return m_name; };
            [[nodiscard]] const std::pair<unsigned int, unsigned int>& getResolution() const override { return m_resolution; };
            [[nodiscard]] const unsigned int& getFramerate() const override { return m_framerate; };

        private:

            std::string m_name{"Default name"};
            std::pair<unsigned int, unsigned int> m_resolution{1920, 1080};
            unsigned int m_framerate{90};

    }; // class ARenderer

} // namespace gui
