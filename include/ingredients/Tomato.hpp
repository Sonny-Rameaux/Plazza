/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Workspace)
** File description:
** Tomato.hpp
*/

#include "AIngredient.hpp"
#pragma once

#define TOMATO "tomato"

class Tomato : public AIngredient {
    public:
        Tomato(std::size_t q);
        ~Tomato() = default;
};
