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
#include "GUI/KeyBoard.hpp"

namespace gui {

    class IRenderer : public IPlugin {

        public:

            virtual void setFPS(unsigned int FPS) = 0;

            [[nodiscard]] virtual IClient& getClient() = 0;
            [[nodiscard]] virtual bool isRunning() = 0;

            virtual void init(const std::string &name, std::pair<const unsigned int,const unsigned int> resolution, unsigned int bitsPerPixel) = 0;
            virtual void render() = 0;
            virtual KeyBoard::Key getEvents() = 0;
            virtual void close() = 0;

    }; // class IRenderer

} // namespace gui
