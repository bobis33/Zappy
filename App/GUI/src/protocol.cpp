/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** protocol
*/

#include "GUI/Protocol.hpp"
#include "GUI/Player.hpp"

const std::unordered_map<std::string, std::function<void(gui::Gui&, std::string)>> gui::Protocol::ProtocolMap = {
        {"msz", [](Gui &gui, const std::string &cmd) {
            gui.initMap({
                std::stoi(cmd.substr(0, cmd.find(' '))),
                std::stoi(cmd.substr(cmd.find(' ') + 1, cmd.size()))
            });
        }},
        {"bct", [](Gui &gui, std::string cmd) {
            gui.getMap().addTile(Parser::parseTileContent(cmd));
        }},
        {"tna", [](Gui &gui, const std::string &cmd) {
            gui.addTeamName(cmd);
        }},
        {"pnw", [](Gui &gui, const std::string &cmd) {
            std::vector<std::string> data = Protocol::parseCommand(cmd);
            Player player;
            player.setOrientation(Parser::parseOrientation(data[3]));
            player.setId(static_cast<unsigned int>(std::stoi(data[0])));
            player.getPosition().x = static_cast<unsigned int>(std::stoi(data[1]));
            player.getPosition().y = static_cast<unsigned int>(std::stoi(data[2]));
            player.setLevel(static_cast<unsigned int>(std::stoi(data[4])));
            player.setTeamName(data[5]);
            gui.addPlayer(player);
        }},
        {"ppo", [](Gui &gui, const std::string &cmd) {
            std::vector<std::string> data = Protocol::parseCommand(cmd);
            for (auto &player : gui.getPlayers()) {
                if (player.getId() != static_cast<unsigned int>(std::stoi(data[0]))) {
                    continue;
                }
                player.getPosition().x = static_cast<unsigned int>(std::stoi(data[1]));
                player.getPosition().y = static_cast<unsigned int>(std::stoi(data[2]));
                player.setOrientation(Parser::parseOrientation(data[3]));
            };

            // to finish -> no need to create a new player, just update the existing one based on the id
        }},
        {"plv", [](Gui &gui, const std::string &cmd) {
            std::vector<std::string> data = Protocol::parseCommand(cmd);
            for (auto &player : gui.getPlayers()) {
                if (player.getId() == static_cast<unsigned int>(std::stoi(data[0]))) {
                    player.setLevel(static_cast<unsigned int>(std::stoi(data[1])));
                }
            }

            // to finish
        }},
        {"pin", [](Gui &gui, const std::string &cmd) {
            std::vector<std::string> data = Protocol::parseCommand(cmd);
            for (auto &player : gui.getPlayers()) {
                if (player.getId() != static_cast<unsigned int>(std::stoi(data[0]))) {
                    continue;
                }
                for (size_t i = 0; i < 7; i++) {
                    player.getInventory().setQuantity(static_cast<Resource::Type>(i), static_cast<unsigned int>(std::stoi(data[i + 3])));
                }
            }

            // to finish
        }},
        {"pex", [](Gui &gui, const std::string &cmd) {
            int playerId = std::stoi(cmd.substr(1, cmd.size()));
            // expulse player
        }},
        {"pbc", [](Gui &gui, const std::string &cmd) {
            std::vector<std::string> data = Protocol::parseCommand(cmd);
            for (auto &player : gui.getPlayers()) {
                if (player.getId() != static_cast<unsigned int>(std::stoi(data[0]))) {
                    continue;
                }
                std::string broadcastMsg = cmd.substr(cmd.find(' ') + 1, cmd.size());
                player.setBroadcast(broadcastMsg);
            }
        }},
        {"pic", [](Gui &gui, const std::string &cmd) {
            std::vector<std::string> data = Protocol::parseCommand(cmd);
            std::vector<int> players;
            unsigned int x = std::stoi(data[0]);
            unsigned int y = std::stoi(data[1]);
            unsigned int level = std::stoi(data[2]);

            // start incantation
        }},
        {"pie", [](Gui &gui, const std::string &cmd) {
            std::vector<std::string> data = Protocol::parseCommand(cmd);
            unsigned int x = std::stoi(data[0]);
            unsigned int y = std::stoi(data[1]);
            unsigned int result = std::stoi(data[2]);
            // end incantation
        }},
        {"pfk", [](Gui &gui, const std::string &cmd) {
            std::vector<std::string> data = Protocol::parseCommand(cmd);
            int playerId = std::stoi(data[0].substr(1, data[0].size()));
            // start egg laying
        }},
        {"pdr", [](Gui &gui, const std::string &cmd) {
            std::vector<std::string> data = Protocol::parseCommand(cmd);
            int playerId = std::stoi(data[0].substr(1, data[0].size()));
            int resourceId = std::stoi(data[1]);
            // drop resource
        }},
        {"pgt", [](Gui &gui, const std::string &cmd) {
            std::vector<std::string> data = Protocol::parseCommand(cmd);
            int playerId = std::stoi(data[0]);
            int resourceId = std::stoi(data[1]);
            // set action
            auto player = std::find_if(gui.getPlayers().begin(), gui.getPlayers().end(),
                [playerId](const Player &p) { return p.getId() == playerId; });
            if (player != gui.getPlayers().end()) {
                player->setLastAction(player->getAction());
                player->setAction(Player::Action::TAKE);
            }
        }},
        {"pdi", [](Gui &gui, const std::string &cmd) {
            std::vector<std::string> data = Protocol::parseCommand(cmd);
            int playerId = std::stoi(data[0]);
            auto player = std::find_if(gui.getPlayers().begin(), gui.getPlayers().end(),
                [playerId](const Player &p) { return p.getId() == playerId; });
            if (player != gui.getPlayers().end()) {
                player->setLastAction(player->getAction());
                player->setAction(Player::Action::DEATH);
            }
            gui.removePlayer(static_cast<unsigned int>(std::stoi(data[0])));
            // player death
        }},
        {"enw", [](Gui &gui, const std::string &cmd) {
            std::vector<std::string> data = Protocol::parseCommand(cmd);
            gui.addEgg(Parser::parseEggContent(data));
        }},
        {"ebo", [](Gui &gui, const std::string &cmd) {
            /*
            gui.matureEgg(std::stoi(cmd.substr(1, cmd.size())));
             */

            // to finish
        }},
        {"edi", [](Gui &gui, const std::string &cmd) {
            gui.eggDeath(std::stoi(cmd));
        }},
        {"sgt", [](Gui &gui, const std::string &cmd) {
            gui.setFrequency(std::stoi(cmd));
        }},
        {"sst", [](Gui &gui, const std::string &cmd) {
            gui.setFrequency(std::stoi(cmd));
        }},
        {"seg", [](Gui &gui, const std::string &) {
            gui.setMode(Gui::RendererMode::END);
        }},
        {"smg", [](Gui &, const std::string &cmd) {
            std::cout << "Server message : " << cmd << "\n";
            // display server message
        }},
        {"suc", [](Gui &, const std::string &) {
            std::cout << "Unknown command\n";
        }},
        {"sbp", [](Gui &, const std::string &) {
            std::cout << "Bad parameters\n";
        }},
};
