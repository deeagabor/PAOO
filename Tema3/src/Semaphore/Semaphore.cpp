#include "Semaphore.hpp"

Semaphore::Semaphore(int count) : count(count) {}

void Semaphore::wait() {
    std::unique_lock<std::mutex> lock(mutex);
    condition.wait(lock, [this]() { return count > 0; });
    --count;
}

void Semaphore::notify() {
    std::unique_lock<std::mutex> lock(mutex);
    ++count;
    condition.notify_one();
}
