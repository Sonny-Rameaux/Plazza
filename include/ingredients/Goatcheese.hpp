/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Workspace)
** File description:
** Goatcheese.hpp
*/

#include "AIngredient.hpp"
#pragma once

#define GOATCHEESE "goatcheese"

class Goatcheese : public AIngredient {
    public:
        Goatcheese(std::size_t q);
        ~Goatcheese() = default;
};
