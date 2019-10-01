
#include <gtest/gtest.h>
#include <thread/pool_factory.h>


using namespace Thread;


TEST(ThreadFactoryTest, ItCreatesAThreadPool) {
    
    PoolFactory pool;

    pool.make(5, [](const unsigned int threadId) {
        // 
    });

    EXPECT_TRUE(true);
};
