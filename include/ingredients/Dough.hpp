/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Workspace)
** File description:
** Dough.hpp
*/

#include "AIngredient.hpp"
#pragma once

#define DOUGH "dough"

class Dough : public AIngredient {
    public:
        Dough(std::size_t q);
        ~Dough() = default;
};
