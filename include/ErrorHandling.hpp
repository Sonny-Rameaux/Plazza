/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** ErrorHandling
*/

#pragma once
#include "main.hpp"
#include <chrono>

class ErrorHandling {
    public:
        static bool checkArgs(
            int ac,
            char **argv,
            double &timeMultiplier,
            std::size_t &nCooks,
            std::chrono::milliseconds &refillTimer
        );

    protected:
    private:
};
