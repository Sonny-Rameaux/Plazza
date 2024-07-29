/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** Margarita
*/

#include "../../include/pizzas/Margarita.hpp"

Margarita::Margarita(PizzaSize size) : APizza(
    PizzaType::MARGARITA,
    size,
    std::vector<std::shared_ptr<IIngredient>>{
        IngredientFactory::createIngredient(DOUGH, 1),
        IngredientFactory::createIngredient(TOMATO, 1),
        IngredientFactory::createIngredient(GRUYERE, 1)
    },
    std::chrono::seconds(1)
)
{
}
