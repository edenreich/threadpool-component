#ifndef THREAD_FACTORY_POOL_H
#define THREAD_FACTORY_POOL_H

#include "interfaces/pool_interface.h"

#include <mutex>
#include <thread>
#include <queue>
#include <atomic>
#include <condition_variable>


namespace Thread {

    class PoolFactory {

        public:

            /**
             * Delete the default constructor.
             */
            PoolFactory() = delete;

            /**
             * Create a pool by given number of threads.
             * 
             * @param const unsigned int threadCount
             * @return Interfaces::PoolInterface *
             */
            static Interfaces::PoolInterface * make(const unsigned int threadCount);

    };

}


#endif // THREAD_FACTORY_POOL_H
