/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Workspace)
** File description:
** Gruyere.hpp
*/

#include "AIngredient.hpp"
#pragma once

#define GRUYERE "gruyere"

class Gruyere : public AIngredient {
    public:
        Gruyere(std::size_t q);
        ~Gruyere() = default;
};
