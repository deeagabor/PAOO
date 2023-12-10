#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
#include "Semaphore.hpp"

// Declaration and initialization of a shared pointer
std::shared_ptr<int> sharedCounter1(new int(0));
std::shared_ptr<int> sharedCounter2 (sharedCounter1);

// Declaration and initialization of a unique pointer
std::unique_ptr<int> uniqueCounter1(new int(21));
std::unique_ptr<int> uniqueCounter2 = std::move(uniqueCounter1);

// Semaphore declaration
Semaphore semaphore(1);

void shared_producer();
void shared_consumer();

void unique_producer();
void unique_consumer();

int main() {
    std::cout<<sharedCounter1.use_count() << std::endl; 
    std::cout<<sharedCounter2.use_count() << std::endl; 

    sharedCounter1.reset();
    std::cout<<sharedCounter2.use_count() << std::endl; 

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

            (*sharedCounter2)++;
            std::cout << "Shared Produced: " << *sharedCounter2 << std::endl;

            semaphore.signal();
        }
    }
}

void shared_consumer() {
    for (int i = 0; i < 5; ++i) {
        {
            semaphore.wait();

            (*sharedCounter2)--;
            std::cout << "Shared Consumed: " << *sharedCounter2 << std::endl;

            // Release semaphore
            semaphore.signal();
        }
    }
}

void unique_producer() {
    for (int i = 0; i < 5; ++i) {
        {
            semaphore.wait();

            (*uniqueCounter2)++;
            std::cout << "Unique Produced: " << *uniqueCounter2 << std::endl;

            semaphore.signal();
        }
    }
}

void unique_consumer() {
    for (int i = 0; i < 5; ++i) {
        {
            semaphore.wait();

            (*uniqueCounter2)--;
            std::cout << "Unique Consumed: " << *uniqueCounter2 << std::endl;

            semaphore.signal();
        }
    }
}