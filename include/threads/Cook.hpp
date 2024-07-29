/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** Cook
*/

#ifndef COOK_HPP_
#define COOK_HPP_

#include "AThread.hpp"

#include "../pizzas/IPizza.hpp"
#include "../SafeQueue.hpp"
#include "Mutex.hpp"
#include "ScopedLock.hpp"
#include "CondVar.hpp"
#include <vector>

#include "../ingredients/Dough.hpp"
#include "../ingredients/Eggplant.hpp"
#include "../ingredients/Goatcheese.hpp"
#include "../ingredients/Gruyere.hpp"
#include "../ingredients/Ham.hpp"
#include "../ingredients/Mushroom.hpp"
#include "../ingredients/Steak.hpp"
#include "../ingredients/Tomato.hpp"

#define COOK_TYPES std::shared_ptr<IPizza>&, std::vector<std::shared_ptr<IIngredient>>&, Mutex&, CondVar&
#define COOK_ARGS std::shared_ptr<IPizza>& pizza, std::vector<std::shared_ptr<IIngredient>>& ingredients, Mutex& mutex, CondVar& cv
#define COOK_NAMES pizza, ingredients, mutex, cv

class Cook : public AThread<void (*)(COOK_TYPES), COOK_TYPES> {
    public:
        Cook(COOK_ARGS);
        ~Cook() = default;

        static void task(COOK_ARGS);
        static bool hasEnoughIngredients(
            std::vector<std::shared_ptr<IIngredient>> pizzaIngredients,
            std::vector<std::shared_ptr<IIngredient>> ingredients
        );
        static void removeIngredients(
            std::vector<std::shared_ptr<IIngredient>> &pizzaIngredients,
            std::vector<std::shared_ptr<IIngredient>> &ingredients
        );

    protected:
    private:
};

#endif /* !COOK_HPP_ */
