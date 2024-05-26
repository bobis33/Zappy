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

            enum class Type {
                FOOD,
                LINEMATE,
                DERAUMERE,
                SIBUR,
                MENDIANE,
                PHIRAS,
                THYSTAME,
                NONE
            };

            Resource(const Type type, const unsigned int quantity);

            bool operator==(const Resource &resource) const
            {
                if (type == resource.type)
                    return true;

                return false;
            }

            Type type;
            double density;
            unsigned int quantity;

    }; // class Resource

} // namespace gui
