/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** PizzaUtils
*/

#ifndef PIZZAUTILS_HPP_
#define PIZZAUTILS_HPP_

#include <map>
#include <string>

enum PizzaType {
    REGINA = 1,
    MARGARITA = 2,
    AMERICANA = 4,
    FANTASIA = 8
};

enum PizzaSize {
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
};

enum Status {
    ALIVE = 1,
    DEAD = 2
};

#endif /* !PIZZAUTILS_HPP_ */
