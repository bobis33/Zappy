/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** protocol
*/

#include "GUI/Protocol.hpp"

const std::unordered_map<std::string, std::function<void(gui::Gui&, std::string)>> gui::Protocol::ProtocolMap = {
        {"msz", [](Gui& gui, const std::string& cmd) {
            gui.initMap({
                std::stoi(cmd.substr(0, cmd.find(' '))),
                std::stoi(cmd.substr(cmd.find(' ') + 1, cmd.size()))
            });
        }},
        {"bct", [](Gui& gui, std::string cmd) {
            gui.getMap().addTile(Parser::parseTileContent(cmd));
        }},
        {"mct", [](Gui& gui, const std::string& cmd) {
            // gui.getMap().countResources();
            std::cout << "mct ok" << std::endl;
        }},
        {"pnw", [](Gui&, const std::string&) {}},
        {"tna", [](Gui& gui, const std::string& cmd) {
            gui.setTeamName(cmd); // Tmp -> add another method after to display the team names in the window
        }},
        {"ppo", [](Gui&, const std::string&) {}},
        {"plv", [](Gui&, const std::string&) {}},
        {"pin", [](Gui&, const std::string&) {}},
        {"pex", [](Gui&, const std::string&) {}},
        {"pbc", [](Gui&, const std::string&) {}},
        {"pic", [](Gui&, const std::string&) {}},
        {"pie", [](Gui&, const std::string&) {}},
        {"pfk", [](Gui&, const std::string&) {}},
        {"pdr", [](Gui&, const std::string&) {}},
        {"pgt", [](Gui&, const std::string&) {}},
        {"pdi", [](Gui&, const std::string&) {}},
        {"enw", [](Gui& gui, const std::string& cmd) {
            gui.initEgg(
                std::stoi(cmd.substr(0, cmd.find(' '))),
                std::stoi(cmd.substr(cmd.find(' ') + 1, cmd.size())),
                {std::stoi(cmd.substr(cmd.find(' ') + 3, cmd.size())),
                 std::stoi(cmd.substr(cmd.find(' ') + 5, cmd.size()))}
            );
        }},
        {"eht", [](Gui& gui, const std::string& cmd) {
            gui.matureEgg(std::stoi(cmd));
        }},
        {"ebo", [](Gui&, const std::string&) {}},
        {"pex", [](Gui&, const std::string&) {}},
        {"sgt", [](Gui& gui, const std::string& cmd) {
            gui.setFrequency(std::stoi(cmd));
        }},
        {"sst", [](Gui& gui, const std::string& cmd) {
            gui.setFrequency(std::stoi(cmd));
        }},
        {"seg", [](Gui&, const std::string&) {}},
        {"smg", [](Gui&, const std::string&) {}},
        {"suc", [](Gui&, const std::string&) {}},
        {"sbp", [](Gui&, const std::string&) {}},
};
