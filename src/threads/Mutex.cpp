/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** Mutex
*/

#include "../../include/threads/Mutex.hpp"

void Mutex::lock()
{
    this->_mutex.lock();
}

void Mutex::unlock()
{
    this->_mutex.unlock();
}

bool Mutex::trylock()
{
   return this->_mutex.try_lock();
}
