/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** ScopedLock
*/

#include "../../include/threads/ScopedLock.hpp"

ScopedLock::ScopedLock(Mutex &mutex) : _mutex(mutex)
{
    this->_mutex.lock();
}

ScopedLock::~ScopedLock()
{
    this->_mutex.unlock();
}
