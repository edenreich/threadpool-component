#include <thread/pool_factory.h>

#include <chrono>
#include <thread>
#include <iostream>


int main(int argc, char ** argv) {

    // Check how many threads supported on the current hardware.
    unsigned int concurentThreadsSupported = std::thread::hardware_concurrency();

    // Create the pool.
    Thread::Interfaces::PoolInterface * pool = Thread::PoolFactory::make(concurentThreadsSupported);

    // Enqueue 10 requests to process, this could be processed simultaneously.
    // It's only push these handlers to the queue, and they will be picked up by the next available thread.
    for (unsigned int request = 1; request <= 10; ++request) {
        pool->enqueue([=](std::thread::id threadId) {            
            // Demonstrate a long running process
            for (unsigned int i = 0; i < 10; i++) {
                std::cout << "\nProcessing Request Nr. " << request << " by thread id " << threadId << '\n';
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
            }

            std::cout << "\nProcessing Request Nr. " << request << " has finished!" << '\n';
        });
    }

    // If for whatever reason the "web server" shutdown, 
    // shutdown also the pool (join the threads to the main context).
    pool->shutdown();

    std::cout << "\nPool has been destroyed" << '\n';

    return 0;
}
