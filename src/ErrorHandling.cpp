/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** ErrorHandling
*/

#include "../include/ErrorHandling.hpp"

bool ErrorHandling::checkArgs(
    int ac,
    char **argv,
    double &timeMultiplier,
    std::size_t &nCooks,
    std::chrono::milliseconds &refillTimer
)
{
    if (ac != 4)
        return false;
    if (!atoi(argv[1]) || !atoi(argv[2]) || !atoi(argv[3]))
        return false;
    if (atoi(argv[1]) <= 0 || atoi(argv[2]) <= 0 || atoi(argv[3]) <= 0)
        return false;
    timeMultiplier = atof(argv[1]);
    nCooks = atoi(argv[2]);
    refillTimer = std::chrono::milliseconds(atoi(argv[3]));
    return true;
};

