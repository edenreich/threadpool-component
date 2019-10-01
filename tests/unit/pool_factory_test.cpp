#include <gtest/gtest.h>
#include <thread/pool_factory.h>

#include <chrono>
#include <thread>
#include <iostream>

using namespace Thread;


TEST(ThreadFactoryTest, ItCreatesAThreadPool) {

    Interfaces::PoolInterface * pool = PoolFactory::make(5);

    pool->enqueue([](std::thread::id threadId) {
        std::cout << "Picked by thread id: " << threadId << '\n';
    });

    pool->enqueue([](std::thread::id threadId) {
        std::cout << "Picked by thread id: " << threadId << '\n';
    });

    delete pool;
};
