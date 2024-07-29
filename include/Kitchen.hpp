/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
#define KITCHEN_HPP_

#include "IPCUtils.hpp"
#include "Reception.hpp"
#include "threads/ThreadPool.hpp"
#include "Process.hpp"
#include "MessageQueue.hpp"
#include "ingredients/IngredientFactory.hpp"
#include "./pizzas/PizzaUtils.hpp"
#include "./pizzas/PizzaFactory.hpp"

#include <iostream>
#include <ctime>
#include <chrono>

#define BASE_INGREDIENT 5

class Kitchen : public Process{
    public:
        Kitchen(std::size_t nCooks, std::chrono::milliseconds refundTime, std::size_t id, std::size_t multiplier);
        ~Kitchen() = default;
        void loop();

        MessageQueue _entry;
        MessageQueue _exit;
        std::size_t _id;
        Status _status;
        void statusValues();
        double _multiplier;
    protected:
    private:
        void interpretMessage(std::string message);
        bool checkTokens(std::vector<std::string> tokens, PizzaType &type, PizzaSize &size);

        ThreadPool _thpool;
        std::clock_t _clock = std::clock();
        std::chrono::milliseconds _refundTime;
        std::size_t _nCooks;

        std::vector<std::shared_ptr<IIngredient>> _ingredients = {
            IngredientFactory::createIngredient(DOUGH, BASE_INGREDIENT),
            IngredientFactory::createIngredient(TOMATO, BASE_INGREDIENT),
            IngredientFactory::createIngredient(GRUYERE, BASE_INGREDIENT),
            IngredientFactory::createIngredient(HAM, BASE_INGREDIENT),
            IngredientFactory::createIngredient(MUSHROOM, BASE_INGREDIENT),
            IngredientFactory::createIngredient(STEAK, BASE_INGREDIENT),
            IngredientFactory::createIngredient(EGGPLANT, BASE_INGREDIENT),
            IngredientFactory::createIngredient(GOATCHEESE, BASE_INGREDIENT)
        };
};

#endif /* !KITCHEN_HPP_ */
