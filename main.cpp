/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** main
*/

#include "include/ErrorHandling.hpp"
#include "include/Reception.hpp"

#include <chrono>

int main(int argc, char **argv) {
    double timeMultiplier;
    std::size_t nCooks;
    std::chrono::milliseconds refillTimer;

    if (!ErrorHandling::checkArgs(argc, argv, timeMultiplier, nCooks, refillTimer))
        return 84;

    try {
        Reception reception;
        reception.loop(timeMultiplier, nCooks, refillTimer);
    }
    catch (...) {
        std::cout << "Error occured." << std::endl;
        return 84;
    }

    return 0;
}
