/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** PizzaFactory
*/

#include "../../include/pizzas/PizzaFactory.hpp"

std::map<PizzaType, std::shared_ptr<IPizza> (*) (PizzaSize)> pizzaList = {
    {REGINA, PizzaFactory::createRegina},
    {MARGARITA, PizzaFactory::createMargarita},
    {AMERICANA, PizzaFactory::createAmericana},
    {FANTASIA, PizzaFactory::createFantasia}
};


std::shared_ptr<IPizza> PizzaFactory::createPizza(PizzaType type, PizzaSize size)
{
    return pizzaList[type](size);
}

std::shared_ptr<IPizza> PizzaFactory::createRegina(PizzaSize size)
{
    return std::make_shared<IPizza>(Regina(size));
}

std::shared_ptr<IPizza> PizzaFactory::createMargarita(PizzaSize size)
{
    return std::make_shared<IPizza>(Margarita(size));
}

std::shared_ptr<IPizza> PizzaFactory::createAmericana(PizzaSize size)
{
    return std::make_shared<IPizza>(Americana(size));
}

std::shared_ptr<IPizza> PizzaFactory::createFantasia(PizzaSize size)
{
    return std::make_shared<IPizza>(Fantasia(size));
}
