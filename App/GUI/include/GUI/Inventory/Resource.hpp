/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Resource.hpp
*/

#pragma once

#include "GUI/RunTimeException.hpp"

namespace gui {

    class Resource {

        public:

            enum Type {
                FOOD = 0,
                LINEMATE = 1,
                DERAUMERE = 2,
                SIBUR = 3,
                MENDIANE = 4,
                PHIRAS = 5,
                THYSTAME = 6,
                NONE = 7
            };

            Resource(Type type, unsigned int quantity);

            bool operator==(const Resource &resource) const
            {
                return type == resource.type;
            }

            Type type;
            double density;
            unsigned int quantity;

    }; // class Resource

} // namespace gui
