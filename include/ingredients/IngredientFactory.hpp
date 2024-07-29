/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** IngredientFactory
*/

#ifndef INGREDIENTFACTORY_HPP_
#define INGREDIENTFACTORY_HPP_

#include "Dough.hpp"
#include "Eggplant.hpp"
#include "Goatcheese.hpp"
#include "Gruyere.hpp"
#include "Ham.hpp"
#include "Mushroom.hpp"
#include "Steak.hpp"
#include "Tomato.hpp"

#include <memory>
#include <map>

class IngredientFactory {
    public:
        static std::shared_ptr<AIngredient> createIngredient(std::string name, std::size_t q);

        static std::shared_ptr<AIngredient> createDough(std::size_t q);
        static std::shared_ptr<AIngredient> createEggplant(std::size_t q);
        static std::shared_ptr<AIngredient> createGoatcheese(std::size_t q);
        static std::shared_ptr<AIngredient> createGruyere(std::size_t q);
        static std::shared_ptr<AIngredient> createHam(std::size_t q);
        static std::shared_ptr<AIngredient> createMushroom(std::size_t q);
        static std::shared_ptr<AIngredient> createSteak(std::size_t q);
        static std::shared_ptr<AIngredient> createTomato(std::size_t q);
    protected:
    private:
};

#endif /* !INGREDIENTFACTORY_HPP_ */
