#ifndef POOL_HANDLER_H
#define POOL_HANDLER_H

#include <functional>
#include <thread>


namespace Thread { 
    namespace Handlers {
        
        typedef std::function<void(std::thread::id threadId)> TaskHandler;

    }
}


#endif // POOL_INTERFACE_H
