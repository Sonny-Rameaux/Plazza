/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** CondVar
*/

#pragma once
#include <condition_variable>

class CondVar {
    public:
        CondVar() = default;
        ~CondVar() = default;

        void notify_one();
        void notify_all();
        void wait(std::unique_lock<std::mutex> &lock);

        template<class Predicate>
        void wait(std::unique_lock<std::mutex> &lock, Predicate pred) {
            _cv.wait(lock, pred);
        }

        template <class Rep, class Period>
        std::cv_status wait_for(
            std::unique_lock<std::mutex>& lock,
            const std::chrono::duration<Rep, Period>& rel_time
        );

        template <class Rep, class Period, class Predicate>
        bool wait_for(
            std::unique_lock<std::mutex>& lock,
            const std::chrono::duration<Rep, Period>& rel_time,
            Predicate pred
        );

    private:
        std::condition_variable _cv;
};
