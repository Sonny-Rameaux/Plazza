/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Workspace)
** File description:
** Mushroom.hpp
*/

#include "AIngredient.hpp"
#pragma once

#define MUSHROOM "mushroom"

class Mushroom : public AIngredient {
    public:
        Mushroom(std::size_t q);
        ~Mushroom() = default;
};
