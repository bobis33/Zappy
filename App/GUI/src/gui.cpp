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

void gui::Gui::Run()
{
    m_renderer->render();
}

gui::Gui::Gui(const gui::Arguments &args)
{
    m_renderer = PluginLoader::getInstance().getPlugin<IRenderer>("SFML");
    m_renderer->setResolution({1920, 1080});
    m_renderer->setName("Zappy");
    m_renderer->setFramerate(60);
    m_renderer->getClient().connect(args.m_port, args.m_machineName);
    if (!m_renderer->getClient().sendCommand("GRAPHIC\n"))
        throw RunTimeException("Failed to send GRAPHIC command");
    if (!m_renderer->getClient().getResponse("WELCOME\n"))
        throw RunTimeException("Failed to receive WELCOME command");

    const std::string &response = m_renderer->getClient().getResponse();
    std::cout << response << std::endl; // to remove
}
