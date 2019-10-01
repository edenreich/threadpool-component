#ifndef POOL_INTERFACE_H
#define POOL_INTERFACE_H

#include "../handlers/task_handler.h"


namespace Thread {
    namespace Interfaces {

        class PoolInterface {

            public:

                /**
                 * Enqueue a task so it can be picked 
                 * up by one of the available threads.
                 * 
                 * @param const Thread::Handlers::TaskHandler & handler
                 * @return void
                 */
                virtual void enqueue(const ::Thread::Handlers::TaskHandler & handler) = 0;

        };

    }
}


#endif // POOL_INTERFACE_H
