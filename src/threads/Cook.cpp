/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** Cook
*/

#include <iostream>
#include "../../include/threads/Cook.hpp"

Cook::Cook(COOK_ARGS) : AThread(this->task, COOK_NAMES)
{
}

void Cook::task(COOK_ARGS)
{
    // ScopedLock lock(mutex);

    // if (!Cook::hasEnoughIngredients(pizza->_ingredients, ingredients)) {
    //     std::unique_lock<std::mutex> lock(mutex.getMutex());
    //     auto predicate = [&] { return Cook::hasEnoughIngredients(pizza->_ingredients, ingredients); };
    //     cv.wait(lock, predicate);
    // }

    // Cook::removeIngredients(pizza->_ingredients, ingredients);
    // lock.~ScopedLock();
    std::cout << "SLEEP STARTED: " << static_cast<double>(pizza->_bakingTime.count()) / 1000.0 << std::endl;
    std::this_thread::sleep_for(pizza->_bakingTime);
    std::cout << "SLEEP ENDED: " << static_cast<double>(pizza->_bakingTime.count()) / 1000.0 << std::endl;
}

bool Cook::hasEnoughIngredients(
    std::vector<std::shared_ptr<IIngredient>> pizzaIngredients,
    std::vector<std::shared_ptr<IIngredient>> ingredients
)
{
    bool checked;

    for (std::size_t i = 0; i < pizzaIngredients.size(); i ++) {
        checked = false;
        for (std::size_t j = 0; j < ingredients.size(); j ++) {
            if (pizzaIngredients[i]->getName() == ingredients[j]->getName()) {
                if (ingredients[j]->getQuantity() < 1)
                    return false;
                checked = true;
                break;
            }
        }
        if (!checked)
            return false;
    }
    return true;
}

void Cook::removeIngredients(
    std::vector<std::shared_ptr<IIngredient>> &pizzaIngredients,
    std::vector<std::shared_ptr<IIngredient>> &ingredients
)
{
    for (std::size_t i = 0; i < pizzaIngredients.size(); i ++) {
        for (std::size_t j = 0; j < ingredients.size(); j ++) {
            if (pizzaIngredients[i]->getName() == ingredients[j]->getName()) {
                ingredients[i]->setQuantity(ingredients[i]->getQuantity() - 1);
                break;
            }
        }
    }
}
