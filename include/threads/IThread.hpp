/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** IThread
*/

#ifndef ITHREAD_HPP_
#define ITHREAD_HPP_

class IThread {
    public:
        virtual ~IThread() = default;

        virtual void join() = 0;

    protected:
    private:
};

#endif /* !ITHREAD_HPP_ */
