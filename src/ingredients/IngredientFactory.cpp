/*

** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** IngredientFactory
*/

#include "../../include/ingredients/IngredientFactory.hpp"

std::map<std::string, std::shared_ptr<AIngredient> (*) (std::size_t)> ingredientList = {
    {DOUGH, IngredientFactory::createDough},
    {EGGPLANT, IngredientFactory::createEggplant},
    {GOATCHEESE, IngredientFactory::createGoatcheese},
    {GRUYERE, IngredientFactory::createGruyere},
    {HAM, IngredientFactory::createHam},
    {MUSHROOM, IngredientFactory::createMushroom},
    {STEAK, IngredientFactory::createSteak},
    {TOMATO, IngredientFactory::createTomato}
};

std::shared_ptr<AIngredient> IngredientFactory::createIngredient(std::string name, std::size_t q)
{
    return ingredientList[name](q);
}

std::shared_ptr<AIngredient> IngredientFactory::createDough(std::size_t q)
{
    return std::make_shared<AIngredient>(Dough(q));
}

std::shared_ptr<AIngredient> IngredientFactory::createEggplant(std::size_t q)
{
    return std::make_shared<AIngredient>(Eggplant(q));
}

std::shared_ptr<AIngredient> IngredientFactory::createGoatcheese(std::size_t q)
{
    return std::make_shared<AIngredient>(Goatcheese(q));
}

std::shared_ptr<AIngredient> IngredientFactory::createGruyere(std::size_t q)
{
    return std::make_shared<AIngredient>(Gruyere(q));
}

std::shared_ptr<AIngredient> IngredientFactory::createHam(std::size_t q)
{
    return std::make_shared<AIngredient>(Ham(q));
}

std::shared_ptr<AIngredient> IngredientFactory::createMushroom(std::size_t q)
{
    return std::make_shared<AIngredient>(Mushroom(q));
}

std::shared_ptr<AIngredient> IngredientFactory::createSteak(std::size_t q)
{
    return std::make_shared<AIngredient>(Steak(q));
}

std::shared_ptr<AIngredient> IngredientFactory::createTomato(std::size_t q)
{
    return std::make_shared<AIngredient>(Tomato(q));
}
