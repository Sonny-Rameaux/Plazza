/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** ScopedLock
*/

#ifndef SCOPEDLOCK_HPP_
#define SCOPEDLOCK_HPP_

#include "Mutex.hpp"

class ScopedLock {
    public:
        ScopedLock(Mutex &mutex);
        ~ScopedLock();

    protected:
    private:
        Mutex &_mutex;
};

#endif /* !SCOPEDLOCK_HPP_ */
