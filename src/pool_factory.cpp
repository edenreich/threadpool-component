#include "include/thread/pool_factory.h"
#include "include/thread/pool.h"

using namespace Thread;


/**
 * Create a pool by given number of threads.
 * 
 * @param const unsigned int threadCount
 * @return const Interfaces::PoolInterface &
 */
const Interfaces::PoolInterface & PoolFactory::make(const unsigned int threadCount)
{
    const Interfaces::PoolInterface & pool = Pool(threadCount);

    return pool;
}
