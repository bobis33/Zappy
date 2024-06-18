/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** gui.cpp
*/

#include <functional>
#include <sstream>

#include "GUI/Constant.hpp"
#include "GUI/Gui.hpp"
#include "GUI/PluginLoader.hpp"
#include "GUI/RunTimeException.hpp"
#include "GUI/Parser.hpp"

static const std::array<std::function<void(gui::Gui &gui)>, gui::KeyBoard::Key::COUNT> EVENT_ARRAY
{
    [](gui::Gui &gui) -> void { gui.getRenderer()->close(); },
    nullptr,
};

gui::Gui::Gui(const gui::Argument &args)
{
    m_renderer = PluginLoader::getInstance().getPlugin<IRenderer>(PLUGIN_RENDERER_SFML.data());
    m_renderer->init(DEFAULT_NAME.data(), DEFAULT_RESOLUTION, DEFAULT_BITS_PER_PIXEL);
    m_renderer->setFPS(DEFAULT_FPS);
    if (!m_renderer->getClient().connect(args.port, args.hostName) ||
        !m_renderer->getClient().sendCommand("GRAPHIC\n") ||
        !m_renderer->getClient().getResponse("WELCOME\n")) {
        throw RunTimeException("Failed to connect to server");
    }

    Parser::processData(Parser::getData(m_renderer->getClient().getResponse()), *this);
}

void gui::Gui::Run()
{
    unsigned long event = 0;

    while (m_renderer->isRunning()) {
        event = static_cast<unsigned long>(m_renderer->getEvents());
        if (event < KeyBoard::Key::COUNT && EVENT_ARRAY.at(event) != nullptr) {
            EVENT_ARRAY.at(event)(*this);
        }
        // Parser::processData(Parser::getData(m_renderer->getClient().getResponse()), *this);
        m_renderer->render(m_map, m_eggs, m_players);
    }
}

void gui::Gui::initMap(const std::pair<unsigned int, unsigned int> &size)
{
    m_map.getTiles().resize(size.second);
    for (auto &row : m_map.getTiles()) {
        row.resize(size.first);
    }
    m_map.setWidth(size.first);
    m_map.setHeight(size.second);
}

void gui::Gui::matureEgg(const unsigned int &eggId)
{
    (void) eggId;
    // Tmp -> remove egg from the map and add a player when a client connects with random direction
}

void gui::Gui::eggDeath(const unsigned int &eggId)
{
    getEggs().at(eggId).setDeath();
}