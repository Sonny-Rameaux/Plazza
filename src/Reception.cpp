/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** Reception
*/

#include "../include/Reception.hpp"

void Reception::loop(
    double timeMultiplier,
    std::size_t nCooks,
    std::chrono::milliseconds refillTimer
)
{
    this->_timeMultiplier = timeMultiplier;
    this->_nCooks = nCooks;
    this->_refillTimer = refillTimer;
    std::string input;
    std::shared_ptr<IPizza> pizza;

    std::cout << "> ";
    while (std::getline(std::cin, input)) {
        if (input == "status") {
            if (this->_kitchens.size() == 0) {
                std::cout << "No kitchens running." << std::endl;
                continue;
            }
            else {
                std::cout << "-------------------------------------" << std::endl << "All kitchen status: " << std::endl;
                for (std::size_t i = 0; i < this->_kitchens.size(); i++) {
                    this->_kitchens[i]->statusValues();
                }
                std::cout << "-------------------------------------" << std::endl;
            }
        }
        else if (input == "exit") {
            for (std::size_t i = 0; i < this->_kitchens.size(); i ++) {
                this->_kitchens[i]->_entry.sendMessage(EXIT);
            }
            break;
        } else {
            this->parseInput(input);
            while (this->_pizzas.tryPop(pizza)) {
                this->sendPizzaToKitchen(pizza);
            }
        }
        std::cout << "> ";
    }
}

void Reception::sendPizzaToKitchen(std::shared_ptr<IPizza> pizza)
{
    std::string msg;
    for (std::size_t i = 0; i < this->_kitchens.size(); i ++) {
        this->_kitchens[i]->_entry.sendMessage(
            std::to_string(pizza->_type)
            + " "
            + std::to_string(pizza->_size)
        );
        if (this->_kitchens[i]->_exit.receiveMessage() == COMMAND_OK) {
            std::cout << "Kitchen[" << this->_kitchens[i]->_id << "] received command." << std::endl;
            return;
        }
    }
    std::shared_ptr<Kitchen> newKitchen = std::make_shared<Kitchen>(this->_nCooks, this->_refillTimer, this->_kitchens.size() + 1, this->_timeMultiplier);
    newKitchen->_entry.sendMessage(
        std::to_string(pizza->_type)
        + " "
        + std::to_string(pizza->_size)
    );
    this->_kitchens.push_back(newKitchen);
    std::cout << "Kitchen[" << newKitchen->_id << "] created." << std::endl;
    if (newKitchen->_exit.receiveMessage() == COMMAND_OK) {
            std::cout << "Kitchen[" << newKitchen->_id << "] received command." << std::endl;
    }
}

void Reception::clearVector(std::vector<std::string> &vector)
{
    std::vector<std::string> dest;

    for (std::size_t i = 0; i < vector.size(); i ++) {
        if (vector[i] != "")
            dest.push_back(vector[i]);
    }

    vector = dest;
}

std::vector<std::string> Reception::parseString(std::string &str, char delim)
{
    std::vector<std::string> dest;
    std::stringstream stream(str);
    std::string token;

    while (getline(stream, token, delim)) {
        dest.push_back(token);
    }

    Reception::clearVector(dest);
    return dest;
}

void Reception::parseInput(std::string &input)
{
    std::vector<std::string> commands = Reception::parseString(input, ';');

    for (std::size_t i = 0; i < commands.size(); i ++) {
        this->parseCommand(commands[i]);
    }
}

std::map<std::string, PizzaType> pizzaStringToType = {
    {"regina", REGINA},
    {"margarita", MARGARITA},
    {"americana", AMERICANA},
    {"fantasia", FANTASIA}
};

std::map<std::string, PizzaSize> pizzaStringToSize = {
    {"S", S},
    {"M", M},
    {"L", L},
    {"XL", XL},
    {"XXL", XXL}
};

bool Reception::convertParameters(
    std::vector<std::string> command,
    PizzaType &type,
    PizzaSize &size,
    std::size_t &num
)
{
    if (command.size() != 3)
        return false;

    if (command[2][0] != 'x')
        return false;

    type = pizzaStringToType[boost::algorithm::to_lower_copy(command[0])];
    size = pizzaStringToSize[boost::algorithm::to_upper_copy(command[1])];
    num = atoi(&command[2][1]);

    return true;
}

void Reception::parseCommand(std::string &command)
{
    std::vector<std::string> parameters = Reception::parseString(command, ' ');
    PizzaType type;
    PizzaSize size;
    std::size_t num;

    if (!convertParameters(parameters, type, size, num)) {
        std::cout << "Failed to parse command." << std::endl;
        return;
    }

    for (std::size_t i = 0; i < num; i ++) {
        std::shared_ptr<IPizza> pizza = PizzaFactory::createPizza(type, size);
        this->_pizzas.push(pizza);
    }
}
