/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Gui
*/

#pragma once

#include <memory>
#include <vector>

#include "GUI/Abstraction/IRenderer.hpp"
#include "GUI/Argument.hpp"
#include "GUI/Map/Map.hpp"
#include "GUI/Player.hpp"

namespace gui {

    class Gui {

        public:

            enum class RendererMode {
                GAME,
                SETTINGS
            };

            explicit Gui(const Argument &args);
            ~Gui() = default;

            std::unique_ptr<IRenderer>& getRenderer() { return m_renderer; };

            void Run();

            void initMap(const std::pair<unsigned, unsigned> &size);
            void initEgg(const unsigned int &eggId, const int &playerId, const std::pair<unsigned int, unsigned int> &pos);
            void matureEgg(const unsigned int &eggId);

            static std::vector<std::string> getData(const std::string &data);
            Map& getMap() { return m_map; };
            int getFrequency() const { return m_frequency; };
            std::vector<std::string>& getTeamNames() { return m_teamNames; };
            std::vector<Player>& getPlayers() { return m_players; };

            void addTeamName(const std::string &teamName) { for (auto &team : m_teamNames) if (team == teamName) return; m_teamNames.push_back(teamName); };
            void addPlayer(const Player &player) { m_players.push_back(player); };
            void setMap(const Map &map) { m_map = map; };
            void setFrequency(int freq) { m_frequency = freq; };

        private:

            std::vector<std::string> m_teamNames;
            std::vector<Player> m_players;
            std::unique_ptr<IRenderer> m_renderer;
            std::vector<std::string> m_data;
            RendererMode m_mode{RendererMode::GAME};
            std::pair<int, int> m_mapSize{0, 0};
            Map m_map{30, 30, {}};
            int m_frequency{0};

    }; // class Gui

} // namespace gui
