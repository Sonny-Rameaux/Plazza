/*
** EPITECH PROJECT, 2023
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** MessageQueue.cpp
*/

#include "../include/MessageQueue.hpp"

MessageQueue::MessageQueue(const std::string &queueName)
{
    _mqd = -1;
    _attr.mq_flags = 0;
    _attr.mq_maxmsg = 10;
    _attr.mq_msgsize = 1024;
    _attr.mq_curmsgs = 0;
    this->_qname = queueName;
    _mqd = mq_open(queueName.c_str(), O_CREAT | O_RDWR, 0666, &_attr);
    if (_mqd == (mqd_t)-1) {
        std::cout << "qname : " << queueName << std::endl;
        throw std::runtime_error("mq_open");
    }
}

MessageQueue::~MessageQueue()
{
    if (_mqd != -1)
        mq_close(_mqd);
    mq_unlink(this->_qname.c_str());
}

std::string MessageQueue::receiveMessage()
{
    std::size_t bytesRead = mq_receive(_mqd, _buffer, 1024, NULL);
    _buffer[bytesRead] = '\0';
    return std::string(_buffer);
}

void MessageQueue::sendMessage(const std::string &message)
{
    if (mq_send(_mqd, message.c_str(), strlen(message.c_str()) + 1, 0) == -1) {
        throw std::runtime_error("mq_send");
    }
}
