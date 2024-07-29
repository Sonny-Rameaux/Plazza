/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** AIngredient
*/

#include "../../include/ingredients/AIngredient.hpp"

AIngredient::AIngredient(std::string name, std::size_t q) : _quantity(q)
{
    this->_name = name;
}

AIngredient& AIngredient::operator--() {
    if (_quantity > 0)
        --_quantity;
    return *this;
}

AIngredient& AIngredient::operator++() {
    ++_quantity;
    return *this;
}

void AIngredient::setQuantity(std::size_t quantity)
{
    this->_quantity = quantity;
}

std::size_t AIngredient::getQuantity()
{
    return this->_quantity;
}

void AIngredient::setName(std::string name)
{
    this->_name = name;
}

std::string AIngredient::getName()
{
    return this->_name;
}
