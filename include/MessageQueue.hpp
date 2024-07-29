/*
** EPITECH PROJECT, 2023
** MessageQueue
** File description:
** MessageQueue.hpp
*/

#pragma once
#include <iostream>
#include <mqueue.h>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>

class MessageQueue {
    public:
        MessageQueue(const std::string &queueName);
        ~MessageQueue();
        std::string receiveMessage();
        void sendMessage(const std::string &message);

        char _buffer[1024];
    private:
        mqd_t _mqd;
        struct mq_attr _attr;
        std::string _qname = "";
};
