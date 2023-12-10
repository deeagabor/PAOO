#include "Semaphore.hpp"

Semaphore::Semaphore(int count) : count(count) {}

void Semaphore::wait() {
    std::unique_lock<std::mutex> lock(mutex);
    while (count == 0) {
        condition.wait(lock);
    }
    count--;
}

void Semaphore::signal() {
    std::unique_lock<std::mutex> lock(mutex);
    ++count;
    condition.notify_one();
}
