/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** PizzaFactory
*/

#ifndef PIZZAFACTORY_HPP_
#define PIZZAFACTORY_HPP_

#include "Regina.hpp"
#include "Margarita.hpp"
#include "Americana.hpp"
#include "Fantasia.hpp"

#include <memory>
#include <map>

class PizzaFactory {
    public:
        static std::shared_ptr<IPizza> createPizza(PizzaType type, PizzaSize size);

        static std::shared_ptr<IPizza> createRegina(PizzaSize size);
        static std::shared_ptr<IPizza> createMargarita(PizzaSize size);
        static std::shared_ptr<IPizza> createAmericana(PizzaSize size);
        static std::shared_ptr<IPizza> createFantasia(PizzaSize size);

    protected:
    private:
};

#endif /* !PIZZAFACTORY_HPP_ */
