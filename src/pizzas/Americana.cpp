/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** Americana
*/

#include "../../include/pizzas/Americana.hpp"

Americana::Americana(PizzaSize size) : APizza(
    AMERICANA,
    size,
    std::vector<std::shared_ptr<IIngredient>>{
        IngredientFactory::createIngredient(DOUGH, 1),
        IngredientFactory::createIngredient(TOMATO, 1),
        IngredientFactory::createIngredient(GRUYERE, 1),
        IngredientFactory::createIngredient(STEAK, 1)
    },
    std::chrono::seconds(2)
)
{
}
