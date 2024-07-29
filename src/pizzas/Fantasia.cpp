/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** Fantasia
*/

#include "../../include/pizzas/Fantasia.hpp"

Fantasia::Fantasia(PizzaSize size) : APizza(
    PizzaType::FANTASIA,
    size,
    std::vector<std::shared_ptr<IIngredient>>{
        IngredientFactory::createIngredient(DOUGH, 1),
        IngredientFactory::createIngredient(TOMATO, 1),
        IngredientFactory::createIngredient(EGGPLANT, 1),
        IngredientFactory::createIngredient(GOATCHEESE, 1)
    },
    std::chrono::seconds(4)
)
{
}
