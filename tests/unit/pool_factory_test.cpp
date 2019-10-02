#include <gtest/gtest.h>
#include <thread/pool_factory.h>

#include <chrono>
#include <thread>
#include <iostream>

using namespace Thread;


TEST(ThreadFactoryTest, ItCreatesAThreadPool) {

    Interfaces::PoolInterface * pool = PoolFactory::make(5);

    pool->enqueue([](std::thread::id threadId) {
        std::cout << '\n' << "Picked by thread id: " << threadId << '\n';
        
        for (unsigned int i = 0; i < 10; i++) {
            std::cout << "Running Task 1..." << threadId << '\n';
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }

        std::cout << "Task 1 finished!" << '\n';
    });

    pool->enqueue([](std::thread::id threadId) {
        std::cout << '\n' << "Picked by thread id: " << threadId << '\n';

        for (unsigned int i = 0; i < 10; i++) {
            std::cout << "Running Task 2..." << threadId << '\n';
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        std::cout << "Task 2 finished!" << '\n';
    });

    std::cin.get();

    // pool->shutdown();
};
