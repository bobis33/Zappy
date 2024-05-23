/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** gui.cpp
*/

#include "GUI/Gui.hpp"
#include "GUI/PluginLoader.hpp"

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
    m_renderer->connect(args.m_port, args.m_machineName);
}
