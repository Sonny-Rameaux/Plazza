/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** Mutex
*/

#ifndef MUTEX_HPP_
#define MUTEX_HPP_

#include <mutex>

class Mutex {
    public:
        Mutex() = default;
        ~Mutex() = default;

        void lock();
        void unlock();
        bool trylock();
        std::mutex &getMutex() { return _mutex;}

    protected:
    private:
        std::mutex _mutex;
};

#endif /* !MUTEX_HPP_ */
