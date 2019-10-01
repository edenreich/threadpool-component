#include <gtest/gtest.h>
#include <thread/pool_factory.h>

#include <thread>
#include <iostream>

using namespace Thread;


TEST(ThreadFactoryTest, ItCreatesAThreadPool) {

    const Interfaces::PoolInterface & pool = PoolFactory::make(5);

    pool.enqueue([](std::thread::id id) {
        std::cout << "TEST" << '\n';
    });

};
