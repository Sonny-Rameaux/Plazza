/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** AThread
*/

#ifndef ATHREAD_HPP_
#define ATHREAD_HPP_

#include "IThread.hpp"
#include <thread>

template <class Func, class... Args>
class AThread : public IThread {
    public:
        AThread(Func task, Args& ... args)
        {
            this->execute(task, args ...);
        };

        ~AThread()
        {
            this->join();
        };

        void execute(Func task, Args& ... args)
        {
            this->_thread = std::thread(task, std::ref(args) ...);
        };

        void join() override {
            if (this->_thread.joinable())
                this->_thread.join();
        };

    protected:
    private:
        std::thread _thread;
};

#endif /* !ATHREAD_HPP_ */
