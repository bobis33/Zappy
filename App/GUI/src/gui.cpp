/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** gui.cpp
*/

#include <functional>
#include <sstream>
#include <iostream>

#include "GUI/Constant.hpp"
#include "GUI/Gui.hpp"
#include "GUI/PluginLoader.hpp"
#include "GUI/RunTimeException.hpp"
#include "GUI/Protocol.hpp"
#include "GUI/Parser.hpp"

static const std::array<std::function<void(gui::Gui &gui)>, gui::KeyBoard::Key::COUNT> EVENT_ARRAY
{
    [](gui::Gui &gui) -> void { gui.getRenderer()->close(); },
    nullptr,
};

void gui::Gui::Run()
{
    unsigned long event = 0;

    while (m_renderer->isRunning()) {
        event = static_cast<unsigned long>(m_renderer->getEvents());
        if (event < KeyBoard::Key::COUNT && EVENT_ARRAY.at(event) != nullptr) {
            EVENT_ARRAY.at(event)(*this);
        }
        m_renderer->render();
    }
}

std::vector<std::string> gui::Gui::getData(const std::string &data)
{
    std::vector<std::string> tmp;
    std::string tmpData;
    std::stringstream ss(data);

    while (std::getline(ss, tmpData, '\n')) {
        tmp.push_back(tmpData);
    }
    return tmp;
}

gui::Gui::Gui(const gui::Argument &args)
{
    std::string command;
    m_renderer = PluginLoader::getInstance().getPlugin<IRenderer>(PLUGIN_RENDERER_SFML.data());
    m_renderer->init(DEFAULT_NAME.data(), DEFAULT_RESOLUTION, DEFAULT_BITS_PER_PIXEL);
    m_renderer->setFPS(DEFAULT_FPS);
    if (!m_renderer->getClient().connect(args.port, args.hostName) ||
        !m_renderer->getClient().sendCommand("GRAPHIC\n") ||
        !m_renderer->getClient().getResponse("WELCOME\n")) {
        throw RunTimeException("Failed to connect to server");
    }

    Parser::processData(getData(m_renderer->getClient().getResponse()), *this);
    // creer methode pour interpreter les commandes -> m_data
    // for (const std::string &line : m_data) {
    //     command = line.substr(0, 3);
    //     std::cout << line << std::endl;
    //     if (ProtocolMap.find(command) != ProtocolMap.end()) {
    //         // std::cout << "Command: " << command << std::endl;
    //     }
    // }
}
