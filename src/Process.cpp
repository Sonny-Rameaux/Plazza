/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** Process
*/

#include "../include/Process.hpp"

Process::Process()
{
    Fork();
}

Process::~Process()
{
    Kill();
}

void Process::Fork()
{
    _pid = fork();
}

void Process::Kill()
{
    kill(_pid, SIGKILL);
}

pid_t Process::getPid()
{
    return _pid;
}
