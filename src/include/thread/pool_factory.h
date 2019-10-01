#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include "interfaces/pool_factory_interface.h"


namespace Thread {

    class PoolFactory : public Interfaces::PoolFactoryInterface {

        public:

            /**
             * Create a pool by given number of threads.
             * 
             * @param const unsigned int threadCount
             * @param Thread::Handlers::PoolHandler handler
             * @return void
             */
            void make(const unsigned int threadCount, Handlers::PoolHandler handler) const override;

        private:
            //

    };

}


#endif // THREAD_POOL_H
