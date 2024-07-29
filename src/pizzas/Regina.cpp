/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** Regina
*/

#include "../../include/pizzas/Regina.hpp"

Regina::Regina(PizzaSize size) : APizza(
    PizzaType::REGINA,
    size,
    std::vector<std::shared_ptr<IIngredient>>{
        IngredientFactory::createIngredient(DOUGH, 1),
        IngredientFactory::createIngredient(TOMATO, 1),
        IngredientFactory::createIngredient(GRUYERE, 1),
        IngredientFactory::createIngredient(HAM, 1),
        IngredientFactory::createIngredient(MUSHROOM, 1)
    },
    std::chrono::seconds(2)
)
{
}
