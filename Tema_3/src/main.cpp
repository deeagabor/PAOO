#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
#include "Semaphore.hpp"

// Declaration and initialization of a shared pointer
std::shared_ptr<int> sharedCounter = std::make_shared<int>(0);

// Declaration and initialization of a unique pointer
std::unique_ptr<int> uniqueCounter(new int(21));

// Semaphore declaration
Semaphore semaphore(1);

void shared_producer();
void shared_consumer();

void unique_producer();
void unique_consumer();

int main() {
   std::thread sharedProducerThread(shared_producer);
    std::thread sharedConsumerThread(shared_consumer);

    // Wait for shared threads to finish
    sharedProducerThread.join();
    sharedConsumerThread.join();

    std::cout<<std::endl;
    std::thread uniqueProducerThread(unique_producer);
    std::thread uniqueConsumerThread(unique_consumer);

    // Wait for unique threads to finish
    uniqueProducerThread.join();
    uniqueConsumerThread.join();

    std::cout << "Main thread finished" << std::endl;

    return 0;
}
 
void shared_producer() {
    for (int i = 0; i < 5; ++i) {
        {
            semaphore.wait();

            (*sharedCounter)++;
            std::cout << "Shared Produced: " << *sharedCounter << std::endl;

            semaphore.notify();
        }
    }
}

void shared_consumer() {
    for (int i = 0; i < 5; ++i) {
        {
            semaphore.wait();

            (*sharedCounter)--;
            std::cout << "Shared Consumed: " << *sharedCounter << std::endl;

            // Release semaphore
            semaphore.notify();
        }
    }
}

void unique_producer() {
    for (int i = 0; i < 5; ++i) {
        {
            semaphore.wait();

            (*uniqueCounter)++;
            std::cout << "Unique Produced: " << *uniqueCounter << std::endl;

            semaphore.notify();
        }
    }
}

void unique_consumer() {
    for (int i = 0; i < 5; ++i) {
        {
            semaphore.wait();

            (*uniqueCounter)--;
            std::cout << "Unique Consumed: " << *uniqueCounter << std::endl;

            semaphore.notify();
        }
    }
}