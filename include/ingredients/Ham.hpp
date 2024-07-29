/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Workspace)
** File description:
** Ham.hpp
*/

#include "AIngredient.hpp"
#pragma once

#define HAM "ham"

class Ham : public AIngredient {
    public:
        Ham(std::size_t q);
        ~Ham() = default;
};
