/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Workspace)
** File description:
** IIngredients.hpp
*/

#include <cstddef>
#include <iostream>

#pragma once

class IIngredient {
    public:
        virtual ~IIngredient() = default;

        virtual void setQuantity(std::size_t quantity) = 0;
        virtual std::size_t getQuantity() = 0;

        virtual void setName(std::string name) = 0;
        virtual std::string getName() = 0;
};
