/*
** EPITECH PROJECT, 2024
** Zappy | GUI
** File description:
** main.cpp
*/

#include <iostream>

#include "GUI/Constant.hpp"
#include "GUI/Gui.hpp"
#include "GUI/Parser.hpp"
#include "GUI/PluginLoader.hpp"
#include "GUI/RunTimeException.hpp"

using namespace gui;

static constexpr const std::string_view HELP_MSG = "USAGE\n"
                                                   "    ./zappy_gui -p port -h machine\n"
                                                   "DESCRIPTION\n"
                                                   "    Zappy GUI\n";

int main(const int argc, char* const argv[])
{
    if (argc == 2 && std::string(argv[1]) == "-help") {
        std::cout << HELP_MSG;
        return EPITECH_EXIT_SUCCESS;
    }
    try {
        if (argc != 5) {
            throw Parser::ParserException("Invalid number of arguments");
        }
        Gui(Parser::getOptions(argc, argv, "p:h:")).Run();
        PluginLoader::getInstance().closePlugins();
    } catch (const PluginLoader::PluginLoaderException &e) {
        std::cerr << "PluginLoaderException: " << e.what() << '\n';
        return EPITECH_EXIT_ERROR;
    } catch (const Parser::ParserException &e) {
        std::cerr << "ParserException: " << e.what() << '\n';
        return EPITECH_EXIT_ERROR;
    } catch (const RunTimeException &e) {
        std::cerr << "RunTimeException: " << e.what() << '\n';
        return EPITECH_EXIT_ERROR;
    } catch (const std::exception &e) {
        std::cerr << "StandardException: " << e.what() << '\n';
        return EPITECH_EXIT_ERROR;
    } catch (...) {
        std::cerr << "Unknown error\n";
        return EPITECH_EXIT_ERROR;
    }
    return EPITECH_EXIT_SUCCESS;
}
