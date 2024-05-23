/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** gui.cpp
*/

#include <iostream>
#include "GUI/Gui.hpp"
#include "GUI/PluginLoader.hpp"
#include "GUI/RunTimeException.hpp"
#include "GUI/Constant.hpp"

void gui::Gui::Run()
{
    m_renderer->render();
}

gui::Gui::Gui(const gui::Arguments &args)
{
    m_renderer = PluginLoader::getInstance().getPlugin<IRenderer>(PLUGIN_RENDERER_SFML.data());
    m_renderer->setResolution(DEFAULT_RESOLUTION);
    m_renderer->setName(DEFAULT_NAME.data());
    m_renderer->setFPS(DEFAULT_FPS);
    m_renderer->getClient().connect(args.m_port, args.m_machineName);

    if (!m_renderer->getClient().sendCommand("GRAPHIC\n") || !m_renderer->getClient().getResponse("WELCOME\n"))
        throw RunTimeException("Failed to connect to server (GRAPHIC or WELCOME cmd)");

    const std::string &response = m_renderer->getClient().getResponse();
    std::cout << response << std::endl; // to remove
}
