/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** Kitchen
*/

#include "../include/Kitchen.hpp"

Kitchen::Kitchen(std::size_t nCooks, std::chrono::milliseconds refundTime, std::size_t id, std::size_t multiplier) :
    Process(),
    _entry(KITCHEN_ENTRY + std::to_string(id)),
    _exit(KITCHEN_EXIT + std::to_string(id)),
    _thpool(nCooks, _ingredients, multiplier)
{
    this->_id = id;
    this->_nCooks = nCooks;
    this->_refundTime = refundTime;
    this->_status = Status::ALIVE;
    this->_multiplier = multiplier;
    if (this->getPid() == 0) {
        this->loop();
    }
}

bool Kitchen::checkTokens(std::vector<std::string> tokens, PizzaType &type, PizzaSize &size)
{
    if (tokens.size() != 2) {
        return false;
    }
    type = static_cast<PizzaType>(atoi(tokens[0].c_str()));
    size = static_cast<PizzaSize>(atoi(tokens[1].c_str()));
    return true;
}

void Kitchen::interpretMessage(std::string message)
{
    std::vector<std::string> tokens = Reception::parseString(message, ' ');
    PizzaType type;
    PizzaSize size;

    if (!this->checkTokens(tokens, type, size)) {
        this->_exit.sendMessage(COMMAND_ERROR);
        return;
    }

    std::shared_ptr<IPizza> pizza = PizzaFactory::createPizza(type, size);
    if (!this->_thpool.enqueue(pizza)) {
        this->_exit.sendMessage(COMMAND_ERROR);
        return;
    }
    this->_exit.sendMessage(COMMAND_OK);
}

void Kitchen::loop() {
    std::string msg;

    while (true) {
        if (_clock >= _refundTime.count()){
            for (std::size_t i = 0; i < _ingredients.size(); i++) {
                std::cout <<_ingredients[i]->getName()<< "(ingredient["<< i << "])" << " = " << _ingredients[i]->getQuantity() << std::endl;
                _ingredients[i]->setQuantity( _ingredients[i]->getQuantity()+1);
                std::cout <<_ingredients[i]->getName() << " = " << _ingredients[i]->getQuantity() << std::endl;
            }
            _clock = std::clock();
        }
        msg = this->_entry.receiveMessage();
        if (msg == EXIT)
            break;
        this->interpretMessage(msg);
    }
}

void Kitchen::statusValues() {
    std::cout << "\tKitchen[" << this->_id << "] status: WORKING" << std::endl;
    for (std::size_t i = 0; i < this->_ingredients.size(); i++)
        std::cout << "\t" << this->_ingredients[i]->getName() << " = " << this->_ingredients[i]->getQuantity() << std::endl << std::endl;
}