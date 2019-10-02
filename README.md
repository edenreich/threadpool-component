
# Thread Pool Component

An easy to use component for creating a thread pool written in C++

## Usage

```cpp
// main.cpp
#include <thread/pool_factory.h>

#include <chrono>
#include <thread>
#include <iostream>


int main(int argc, char ** argv) {

    // Check how many threads supported on the current hardware.
    unsigned int concurentThreadsSupported = std::thread::hardware_concurrency();

    // Create the pool.
    Thread::Interfaces::PoolInterface * pool = Thread::PoolFactory::make(concurentThreadsSupported);

    // Enqueue 10 requests to process, this could be processed simultaneously.
    // It's only push these handlers to the queue, and they will be picked up by the next available thread.
    for (unsigned int request = 1; request <= 10; ++request) {
        pool->enqueue([=](std::thread::id threadId) {            
            // Demonstrate a long running process
            for (unsigned int i = 0; i < 10; i++) {
                std::cout << "\nProcessing Request Nr. " << request << " by thread id " << threadId << '\n';
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
            }

            std::cout << "\nProcessing Request Nr. " << request << " has finished!" << '\n';
        });
    }

    // If for whatever reason the "web server" shutdown, 
    // shutdown also the pool (join the threads to the main context).
    pool->shutdown();

    std::cout << "\nPool has been destroyed" << '\n';

    return 0;
}
```

## Build

Run `cd build && cmake .. && cmake --build . --target install`

## Distributed Files

After building the project all distributed files are located in `build/dist`.

## Target

This project targets all platforms (it's STL-Based).

## Contributing Guidelines

If you find this project interesting or have any suggestions, feel free to send a pull request. I will be more than happy to review it.
