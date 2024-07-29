/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** APizza
*/

#include "../../include/pizzas/APizza.hpp"

APizza::APizza(
    PizzaType type,
    PizzaSize size,
    std::vector<std::shared_ptr<IIngredient>> ingredients,
    std::chrono::milliseconds bakingTime
)
{
    this->_type = type;
    this->_size = size;
    this->_ingredients = ingredients;
    this->_bakingTime = bakingTime;
}
