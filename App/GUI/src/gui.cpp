/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** gui.cpp
*/

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

gui::Gui::Gui(const gui::Argument &args)
{
    m_renderer = PluginLoader::getInstance().getPlugin<IRenderer>(PLUGIN_RENDERER_SFML.data());
    m_renderer->init(DEFAULT_NAME.data(), DEFAULT_RESOLUTION, DEFAULT_BITS_PER_PIXEL);
    m_renderer->setFPS(DEFAULT_FPS);
    if (!m_renderer->getClient().connect(args.port, args.hostName) ||
        !m_renderer->getClient().sendCommand("GRAPHIC\n") ||
        !m_renderer->getClient().getResponse("WELCOME\n"))
        throw RunTimeException("Failed to connect to server");

    m_data = m_renderer->getClient().getResponse();
}
