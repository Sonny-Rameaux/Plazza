/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** Reception
*/

#ifndef RECEPTION_HPP_
#define RECEPTION_HPP_

#include "SafeQueue.hpp"
#include "pizzas/PizzaFactory.hpp"
#include "Kitchen.hpp"
#include "MessageQueue.hpp"
#include "IPCUtils.hpp"

#include <memory>
#include <chrono>
#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>
#include <boost/algorithm/string.hpp>

class Kitchen;

class Reception {
    public:
        Reception() = default;
        ~Reception() = default;

        void loop(
            double timeMultiplier,
            std::size_t nCooks,
            std::chrono::milliseconds refillTimer
        );

        static std::vector<std::string> parseString(std::string &str, char delim);
        static void clearVector(std::vector<std::string> &vector);

    protected:
    private:
        bool convertParameters(std::vector<std::string> command, PizzaType &type, PizzaSize &size, std::size_t &num);
        void parseInput(std::string &input);
        void parseCommand(std::string &command);
        void sendPizzaToKitchen(std::shared_ptr<IPizza> pizza);

        SafeQueue<std::shared_ptr<IPizza>> _pizzas;
        std::vector<std::shared_ptr<Kitchen>> _kitchens;
        double _timeMultiplier;
        std::size_t _nCooks;
        std::chrono::milliseconds _refillTimer;
};

#endif /* !RECEPTION_HPP_ */
