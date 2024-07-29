/*
** EPITECH PROJECT, 2024
** B-CCP-400-MAR-4-1-theplazza-matthieu.bousquet
** File description:
** ThreadPool
*/

#include "../../include/threads/ThreadPool.hpp"

ThreadPool::ThreadPool(std::size_t nCooks, std::vector<std::shared_ptr<IIngredient>> &ingredients, std::size_t multiplier) : _stop(false), _ncooks(nCooks)
{
    for (std::size_t i = 0; i < nCooks; i ++) {
        this->_cooks.emplace_back([this, &ingredients, multiplier] {
            for (;;) {
                std::unique_lock<std::mutex> lock(this->_qMutex);
                this->_cv.wait(lock, [this] {
                    return this->_stop || !this->_queue.empty();
                });
                if (this->_stop && this->_queue.empty()) {
                    lock.unlock();
                    return;
                }
                std::shared_ptr<IPizza> pizza;
                if (!this->_queue.tryPop(pizza)) {
                    lock.unlock();
                    return;
                }
                lock.unlock();
                for (std::shared_ptr<IIngredient> ingr : pizza->_ingredients) {
                    for (std::size_t i = 0; i < ingredients.size(); i++) {
                        if (ingredients[i]->getName() == ingr->getName()) {
                            ingredients[i]->setQuantity(ingredients[i]->getQuantity()-1);
                        }
                        
                    }
                }
                std::this_thread::sleep_for(pizza->_bakingTime * multiplier);
                std::cout << "Finished baking" << std::endl;
            }
        });
    }
}

ThreadPool::~ThreadPool()
{
    std::unique_lock<std::mutex> lock(this->_qMutex);
    this->_stop = true;
    lock.unlock();
    this->_cv.notify_all();
    for (std::thread& cook : this->_cooks) {
        cook.join();
    }
}

bool ThreadPool::enqueue(std::shared_ptr<IPizza> &pizza)
{
    std::unique_lock<std::mutex> lock(this->_qMutex);
    if (this->_queue.size() > this->_ncooks * 2) {
        lock.unlock();
        this->_cv.notify_one();
        return false;
    }
    this->_queue.push(pizza);
    lock.unlock();
    this->_cv.notify_one();
    return true;
}
