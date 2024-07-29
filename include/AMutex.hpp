/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** AMutex
*/

#pragma once
#include "IMutex.hpp"
#include <mutex>
class AMutex : public IMutex {
    public:
        AMutex();
        ~AMutex();
        bool tryLock() override;
        void unlock() override;
    protected:
    private:
        std::mutex _mtx;
};
