/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Gui
*/

#pragma once

#include <memory>
#include <vector>
#include <algorithm>

#include "GUI/Abstraction/IRenderer.hpp"
#include "GUI/Argument.hpp"
#include "GUI/Map/Map.hpp"
#include "GUI/Player.hpp"
#include "GUI/Egg.hpp"

namespace gui {

    class Gui {

        public:

            enum class RendererMode {
                GAME,
                SETTINGS,
                END
            };

            explicit Gui(const Argument &args);
            ~Gui() = default;

            std::unique_ptr<IRenderer>& getRenderer() { return m_renderer; };

            void Run(bool animations);

            void initMap(const std::pair<unsigned, unsigned> &size);
            void matureEgg(const unsigned int &eggId);
            void eggDeath(const unsigned int &eggId);
            void addEgg(const Egg& egg) { m_eggs.push_back(egg);}

            [[nodiscard]] Map& getMap() { return m_map; };
            [[nodiscard]] int getFrequency() const { return m_frequency; };
            [[nodiscard]] std::vector<std::string>& getTeamNames() { return m_teamNames; };
            [[nodiscard]] std::vector<Player>& getPlayers() { return m_players; };
            [[nodiscard]] RendererMode getMode() const { return m_mode; };
            [[nodiscard]] std::vector<Egg> getEggs() const { return m_eggs; };

            void addTeamName(const std::string &teamName) { for (auto &team : m_teamNames) if (team == teamName) return; m_teamNames.push_back(teamName); };
            void addPlayer(const Player &player) { m_players.push_back(player); };
            void removePlayer(const unsigned int &id) { m_players.erase(std::remove_if(m_players.begin(), m_players.end(), [id](const Player &player) { return player.getId() == id; }), m_players.end()); };
            void setMap(const Map &map) { m_map = map; };
            void setFrequency(int freq) { m_frequency = freq; };
            void setMode(RendererMode mode) { m_mode = mode; };

        private:

            std::vector<std::string> m_teamNames;
            std::vector<Player> m_players;
            std::unique_ptr<IRenderer> m_renderer;
            std::vector<std::string> m_data;
            RendererMode m_mode{RendererMode::GAME};
            std::pair<int, int> m_mapSize{0, 0};
            Map m_map{30, 30, {}};
            int m_frequency{0};
            std::vector<Egg> m_eggs;

    }; // class Gui

} // namespace gui
