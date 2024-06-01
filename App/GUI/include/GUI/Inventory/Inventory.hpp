/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Inventory
*/

#pragma once

#include <utility>
#include <vector>

#include "GUI/Inventory/Resource.hpp"

namespace gui {

    class Inventory {

        public:

            Inventory(Resource food, Resource linemate, Resource deraumere, Resource sibur, Resource mendiane, Resource phiras, Resource thystame) :
                resources({food, linemate, deraumere, sibur, mendiane, phiras, thystame}) {};
            explicit Inventory(std::vector<Resource> cresources): resources(std::move(cresources)) {};

            std::vector<Resource> resources;

    }; // class Inventory

} // namespace gui
