/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** SafeQueue
*/
#pragma once

#include <queue>
#include <cstddef>

template <class T>
class SafeQueue {
    public:
        SafeQueue() = default;
        ~SafeQueue() = default;

        void push(T &value);
        bool tryPop(T &value);
        bool empty();
        std::size_t size();

    protected:
    private:
        std::queue<T> queue;
};

template <class T>
void SafeQueue<T>::push(T &value)
{
    this->queue.push(value);
}

template <class T>
bool SafeQueue<T>::tryPop(T &value)
{
    if (this->queue.empty())
        return false;

    value = this->queue.front();
    this->queue.pop();
    return true;
}

template <class T>
bool SafeQueue<T>::empty()
{
    return this->queue.empty();
}

template <class T>
std::size_t SafeQueue<T>::size()
{
    return this->queue.size();
}
