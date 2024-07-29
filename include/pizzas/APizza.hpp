/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** APizza
*/

#ifndef APIZZA_HPP_
#define APIZZA_HPP_

#include "IPizza.hpp"

#include "../ingredients/Dough.hpp"
#include "../ingredients/Eggplant.hpp"
#include "../ingredients/Goatcheese.hpp"
#include "../ingredients/Gruyere.hpp"
#include "../ingredients/Ham.hpp"
#include "../ingredients/Mushroom.hpp"
#include "../ingredients/Steak.hpp"
#include "../ingredients/Tomato.hpp"

class APizza : public IPizza {
    public:
        APizza(
            PizzaType type,
            PizzaSize size,
            std::vector<std::shared_ptr<IIngredient>> ingredients,
            std::chrono::milliseconds bakingTime
        );
        ~APizza() = default;

    protected:
    private:
};

#endif /* !APIZZA_HPP_ */
