#ifndef POOL_HANDLER_H
#define POOL_HANDLER_H

#include <functional>


namespace Thread { 
    namespace Handlers {
        
        typedef std::function<void(const unsigned int threadId)> PoolHandler;

    }
}


#endif // POOL_INTERFACE_H
