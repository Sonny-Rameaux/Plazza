/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** CondVar
*/

#include "../../include/threads/CondVar.hpp"

void CondVar::notify_one()
{
    _cv.notify_one();
}

void CondVar::notify_all()
{
    _cv.notify_all();
}

void CondVar::wait(std::unique_lock<std::mutex> &lock)
{
    _cv.wait(lock);
}

template <class Rep, class Period>
std::cv_status CondVar::wait_for(
    std::unique_lock<std::mutex>& lock,
    const std::chrono::duration<Rep, Period>& rel_time
)
{
    return _cv.wait_for(lock, rel_time);
};

template <class Rep, class Period, class Predicate>
bool CondVar::wait_for(
    std::unique_lock<std::mutex>& lock,
    const std::chrono::duration<Rep, Period>& rel_time,
    Predicate pred
)
{
    return _cv.wait_for(lock, rel_time, pred);
};
