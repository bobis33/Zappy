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
            player.setId(static_cast<unsigned int>(std::stoi(data[0].substr(1, data[0].size()))));
            player.getPosition().x = static_cast<unsigned int>(std::stoi(data[1]));
            player.getPosition().y = static_cast<unsigned int>(std::stoi(data[2]));
            player.setLevel(static_cast<unsigned int>(std::stoi(data[4])));
            player.setTeamName(data[5]);
            gui.addPlayer(player);
        }},
        {"ppo", [](Gui &gui, const std::string &cmd) {
            std::vector<std::string> data = Protocol::parseCommand(cmd);
            for (auto &player : gui.getPlayers()) {
                if (player.getId() != static_cast<unsigned int>(std::stoi(data[0].substr(1, data[0].size())))) {
                    continue;
                }
                player.setOrientation(Parser::parseOrientation(data[3]));
            };

            // to finish -> no need to create a new player, just update the existing one based on the id
        }},
        {"plv", [](Gui &gui, const std::string &cmd) {
            std::vector<std::string> data = Protocol::parseCommand(cmd);
            for (auto &player : gui.getPlayers()) {
                if (player.getId() == static_cast<unsigned int>(std::stoi(data[0].substr(1, data[0].size())))) {
                    player.setLevel(static_cast<unsigned int>(std::stoi(data[1])));
                }
            }

            // to finish
        }},
        {"pin", [](Gui &gui, const std::string &cmd) {
            std::vector<std::string> data = Protocol::parseCommand(cmd);
            for (auto &player : gui.getPlayers()) {
                if (player.getId() != static_cast<unsigned int>(std::stoi(data[0].substr(1, data[0].size())))) {
                    continue;
                }
                for (size_t i = 0; i < 6; i++) {
                    player.getInventory().setQuantity(static_cast<Resource::Type>(i), static_cast<unsigned int>(std::stoi(data[i + 3])));
                }
            }

            // to finish
        }},
        {"pex", [](Gui&, const std::string&) {}},
        {"pbc", [](Gui&, const std::string&) {}},
        {"pic", [](Gui&, const std::string&) {}},
        {"pie", [](Gui&, const std::string&) {}},
        {"pfk", [](Gui&, const std::string&) {}},
        {"pdr", [](Gui&, const std::string&) {}},
        {"pgt", [](Gui&, const std::string&) {}},
        {"pdi", [](Gui&, const std::string&) {}},
        {"enw", [](Gui &, const std::string &) {
            /*
            gui.initEgg(
                std::stoi(cmd.substr(0, cmd.find(' '))),
                std::stoi(cmd.substr(cmd.find(' ') + 1, cmd.size())),
                {std::stoi(cmd.substr(cmd.find(' ') + 3, cmd.size())),
                 std::stoi(cmd.substr(cmd.find(' ') + 5, cmd.size()))}
            );
             */

            // to finish
        }},
        {"ebo", [](Gui &, const std::string &) {
            /*
            gui.matureEgg(std::stoi(cmd.substr(1, cmd.size())));
             */

            // to finish
        }},
        {"edi", [](Gui &, const std::string &) {
            /*
            gui.eggDeath(std::stoi(cmd.substr(1, cmd.size());
            */

           // to finish
        }},
        {"sgt", [](Gui &gui, const std::string &cmd) {
            gui.setFrequency(std::stoi(cmd));
        }},
        {"sst", [](Gui &gui, const std::string &cmd) {
            gui.setFrequency(std::stoi(cmd));
        }},
        {"seg", [](Gui&, const std::string &) {
            // end game, cmd = teamName
        }},
        {"smg", [](Gui&, const std::string &cmd) {
            std::cout << "Server message : " << cmd << "\n";
            // display server message
        }},
        {"suc", [](Gui &, const std::string&) {
            std::cout << "Unknown command\n";
        }},
        {"sbp", [](Gui&, const std::string&) {
            std::cout << "Bad parameters\n";
        }},
};
