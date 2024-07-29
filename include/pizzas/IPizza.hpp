/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** IPizza
*/

#ifndef IPIZZA_HPP_
#define IPIZZA_HPP_

#include "PizzaUtils.hpp"
#include "../ingredients/IngredientFactory.hpp"

#include <vector>
#include <string>
#include <chrono>
#include <memory>

class IPizza {
    public:
        virtual ~IPizza() = default;

        enum PizzaType _type;
        enum PizzaSize _size;
        std::vector<std::shared_ptr<IIngredient>> _ingredients;
        std::chrono::milliseconds _bakingTime;
    protected:
    private:
};

#endif /* !IPIZZA_HPP_ */
