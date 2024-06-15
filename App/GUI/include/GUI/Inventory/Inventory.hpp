/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Inventory
*/

#pragma once

#include <vector>

#include "GUI/Inventory/Resource.hpp"

namespace gui {

    class Inventory {

        public:

            Inventory() = default;

            Inventory(Resource food, Resource linemate, Resource deraumere, Resource sibur, Resource mendiane, Resource phiras, Resource thystame) :
                resources({food, linemate, deraumere, sibur, mendiane, phiras, thystame}) {};
            explicit Inventory(std::vector<Resource> cresources): resources(std::move(cresources)) {};

            void setQuantity(Resource::Type type, unsigned int quantity) {
                for (auto &resource : resources) {
                    if (resource.type == type) {
                        resource.quantity = quantity;
                        return;
                    }
                }
            };

            std::vector<Resource> resources;

    }; // class Inventory

} // namespace gui
