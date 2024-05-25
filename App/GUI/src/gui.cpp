/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** gui.cpp
*/

#include <iostream>
#include <functional>

#include "GUI/Constant.hpp"
#include "GUI/Gui.hpp"
#include "GUI/PluginLoader.hpp"
#include "GUI/RunTimeException.hpp"

static const std::function<void(gui::Gui &)> EVENT_ARRAY[gui::KeyBoard::Key::COUNT]
{
    [](gui::Gui &gui) -> void { gui.getRenderer()->close(); },
    nullptr,
};

void gui::Gui::Run()
{
    KeyBoard::Key event;

    while (m_renderer->isRunning()) {
        event = m_renderer->getEvents();
        if (event < KeyBoard::Key::COUNT && EVENT_ARRAY[event] != nullptr) {
            EVENT_ARRAY[event](*this);
        }
        m_renderer->render();
    }
}

gui::Gui::Gui(const gui::Arguments &args)
{
    m_renderer = PluginLoader::getInstance().getPlugin<IRenderer>(PLUGIN_RENDERER_SFML.data());
    m_renderer->init(DEFAULT_RESOLUTION, DEFAULT_NAME.data());
    m_renderer->setFPS(DEFAULT_FPS);
    if (!m_renderer->getClient().connect(args.m_port, args.m_machineName) ||
        !m_renderer->getClient().sendCommand("GRAPHIC\n") ||
        !m_renderer->getClient().getResponse("WELCOME\n"))
        throw RunTimeException("Failed to connect to server");

    const std::string &response = m_renderer->getClient().getResponse();
    std::cout << response << std::endl; // to remove
}
