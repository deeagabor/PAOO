#pragma once

#include <mutex>
#include <condition_variable>

class Semaphore {
    public:
        Semaphore(int count = 0);
        void wait();
        void signal();

    private:
        std::mutex mutex;
        std::condition_variable condition;
        int count;
};