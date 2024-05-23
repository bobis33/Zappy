/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** IRenderer
*/

#pragma once

#include <cstdint>

#include "GUI/Abstraction/IPlugin.hpp"
#include "GUI/Abstraction/IClient.hpp"

namespace gui {

    class IRenderer : public IPlugin {

        public:

            virtual void setName(const std::string& name) = 0;
            virtual void setResolution(const std::pair<unsigned int, unsigned int>& resolution) = 0;
            virtual void setFramerate(unsigned int framerate) = 0;

            [[nodiscard]] virtual const std::string& getName() const = 0;
            [[nodiscard]] virtual const std::pair<unsigned int, unsigned int>& getResolution() const = 0;
            [[nodiscard]] virtual const unsigned int& getFramerate() const = 0;
            [[nodiscard]] virtual IClient& getClient() = 0;

            virtual void render() = 0;
            virtual void handleEvents() = 0;

    }; // class IRenderer

} // namespace gui
