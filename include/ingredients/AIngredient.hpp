/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Workspace)
** File description:
** AIngredients.hpp
*/

#include "IIngredient.hpp"

#pragma once

class AIngredient : public IIngredient {
    public:
        AIngredient(std::string _name, std::size_t q);
        ~AIngredient() = default;

        void setQuantity(std::size_t quantity) override;
        std::size_t getQuantity() override;

        void setName(std::string name) override;
        std::string getName()override;

        AIngredient& operator--();
        AIngredient& operator++();
    private:
        std::size_t _quantity = 0;
        std::string _name = "";
};
