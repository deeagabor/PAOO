#pragma once

#include <mutex>
#include <condition_variable>

class Semaphore {
    public:
        Semaphore(int count = 0);
        void wait();
        void notify();

    private:
        std::mutex mutex;
        std::condition_variable condition;
        int count;
};