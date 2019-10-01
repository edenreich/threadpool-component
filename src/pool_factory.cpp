#include "include/thread/pool_factory.h"
#include "include/thread/pool.h"

using namespace Thread;


/**
 * Create a pool by given number of threads.
 * 
 * @param const unsigned int threadCount
 * @return Interfaces::PoolInterface *
 */
Interfaces::PoolInterface * PoolFactory::make(const unsigned int threadCount)
{
    Interfaces::PoolInterface * pool = new Pool(threadCount);

    return pool;
}
