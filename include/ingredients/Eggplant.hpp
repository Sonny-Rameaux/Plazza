/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Workspace)
** File description:
** Eggplant.hpp
*/

#include "AIngredient.hpp"
#pragma once

#define EGGPLANT "eggplant"

class Eggplant : public AIngredient {
    public:
        Eggplant(std::size_t q);
        ~Eggplant() = default;
};
