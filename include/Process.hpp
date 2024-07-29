/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** Processes
*/

#pragma once
#include <unistd.h>
#include <signal.h>

class Process {
    public:
        Process();
        ~Process();
        void Kill();
        void Fork();
        pid_t getPid();
    protected:
    private:
        pid_t _pid;
};
