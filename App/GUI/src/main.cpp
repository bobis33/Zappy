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

int main(const int argc, char* const argv[])
{
    try {
        if (argc != 2 && argc != 5) {
            throw Parser::ParserException("Invalid number of arguments");
        }
        Gui(Parser::ParseArgs(argc, argv)).Run();
        PluginLoader::getInstance().closePlugins();
    } catch (const Parser::ParserException &e) {
        std::cerr << e.what() << '\n';
        return EPITECH_EXIT_ERROR;
    } catch (const RunTimeException &e) {
        std::cerr << e.what() << '\n';
        return EPITECH_EXIT_ERROR;
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
        return EPITECH_EXIT_ERROR;
    } catch (...) {
        std::cerr << "Unknown error\n";
        return EPITECH_EXIT_ERROR;
    }
    return EPITECH_EXIT_SUCCESS;
}
