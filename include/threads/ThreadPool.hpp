/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** ThreadPool
*/

#ifndef THREADPOOL_HPP_
#define THREADPOOL_HPP_

#include "Cook.hpp"
#include "Mutex.hpp"
#include "../SafeQueue.hpp"
#include "CondVar.hpp"

#include <iostream>
#include <vector>
#include <unistd.h>

class ThreadPool {
    public:
        ThreadPool(std::size_t nCooks, std::vector<std::shared_ptr<IIngredient>> &ingredients, std::size_t multiplier);
        ~ThreadPool();

        bool enqueue(std::shared_ptr<IPizza> &pizza);
    protected:
    private:
        std::size_t _ncooks;
        std::size_t _multiplier;
        std::vector<std::thread> _cooks;
        std::mutex _qMutex;
        std::condition_variable _cv;
        SafeQueue<std::shared_ptr<IPizza>> _queue;
        bool _stop;
};

#endif /* !THREADPOOL_HPP_ */
