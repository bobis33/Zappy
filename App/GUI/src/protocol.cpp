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
            Player::Orientation orientation;
            Player player;
            switch (std::stoi(data[3])) {
                case 1:
                    orientation = Player::Orientation::NORTH;
                    break;
                case 2:
                    orientation = Player::Orientation::EAST;
                    break;
                case 3:
                    orientation = Player::Orientation::SOUTH;
                    break;
                case 4:
                    orientation = Player::Orientation::WEST;
                    break;

                default:
                    orientation = Player::Orientation::NORTH;
            }
            player.setId(static_cast<unsigned int>(std::stoi(data[0].substr(1, data[0].size()))));
            player.getPosition().x = static_cast<unsigned int>(std::stoi(data[1]));
            player.getPosition().y = static_cast<unsigned int>(std::stoi(data[2]));
            player.setOrientation(orientation);
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
                switch (std::stoi(data[3])) {
                    case 1:
                        player.setOrientation(Player::Orientation::NORTH);
                        break;
                    case 2:
                        player.setOrientation(Player::Orientation::EAST);
                        break;
                    case 3:
                        player.setOrientation(Player::Orientation::SOUTH);
                        break;
                    case 4:
                        player.setOrientation(Player::Orientation::WEST);
                        break;

                    default:
                        player.setOrientation(Player::Orientation::NORTH);
                }
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
