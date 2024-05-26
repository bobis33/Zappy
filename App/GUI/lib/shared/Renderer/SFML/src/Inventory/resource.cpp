/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** resource
*/

#include "GUI/Mob/Inventory/Resource.hpp"

gui::Resource::Resource(const Type ctype, const unsigned int cquantity) : type(ctype), quantity(cquantity)
{
    switch (type) {
        case Type::FOOD:
            density = 0.5;
            break;
        case Type::LINEMATE:
            density = 0.3;
            break;
        case Type::DERAUMERE:
            density = 0.15;
            break;
        case Type::SIBUR:
            density = 0.1;
            break;
        case Type::MENDIANE:
            density = 0.1;
            break;
        case Type::PHIRAS:
            density = 0.08;
            break;
        case Type::THYSTAME:
            density = 0.05;
            break;

        default:
            throw RunTimeException("Unknown resource type");
    }
}
