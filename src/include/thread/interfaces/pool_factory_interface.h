#ifndef POOL_INTERFACE_H
#define POOL_INTERFACE_H

#include "../handlers/pool_handler.h"


namespace Thread {
    namespace Interfaces {

        class PoolFactoryInterface {

            public:

                /**
                 * Create a pool by given number of threads.
                 * 
                 * @param const unsigned int threadCount
                 * @param ::Thread::Handlers::PoolHandler handler
                 * @return void
                 */
                virtual void make(const unsigned int threadCount, ::Thread::Handlers::PoolHandler handler) const = 0;

        };

    }
}


#endif // POOL_INTERFACE_H
