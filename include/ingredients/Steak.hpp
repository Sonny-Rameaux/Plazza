/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Workspace)
** File description:
** Steak.hpp
*/

#include "AIngredient.hpp"
#pragma once

#define STEAK "steak"

class Steak : public AIngredient {
    public:
        Steak(std::size_t q);
        ~Steak() = default;
};
