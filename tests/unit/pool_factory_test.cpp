#include <gtest/gtest.h>
#include <thread/pool_factory.h>

#include <chrono>
#include <thread>
#include <iostream>


TEST(ThreadFactoryTest, DISABLED_ItCreatesAThreadPool) {

    // Check how many threads supported on the current hardware.
    unsigned int concurentThreadsSupported = std::thread::hardware_concurrency();

    // Create the pool.
    Thread::Interfaces::PoolInterface * pool = Thread::PoolFactory::make(concurentThreadsSupported);

    // Enqueue 10 requests to process, this could be processed simultaneously
    // it's only push these handlers to the queue, and they will be picked up by the next available thread,
    // in this case we only have 10 threads in the pool, but you can increase it, depending on your hardware.
    for (unsigned int request = 1; request <= 10; ++request) {
        pool->enqueue([=](std::thread::id threadId) {            
            // Demonstrate a long running process
            for (unsigned int i = 0; i < 10; i++) {
                std::cout << "\nProcessing Request Nr. " << request << " by process id " << threadId << '\n';
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
            }

            std::cout << "\nProcessing " << request << " finished!" << '\n';
        });
    }

    // If for whatever reason the webserver cannot exit the loop,
    pool->shutdown();

    std::cout << "\nPool has been destroyed" << '\n';
};
