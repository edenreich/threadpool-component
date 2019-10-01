#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include "interfaces/pool_interface.h"

#include <mutex>
#include <thread>
#include <queue>
#include <atomic>
#include <condition_variable>


namespace Thread {

    class Pool : public Interfaces::PoolInterface {

        public:

            /**
             * Constructor
             * 
             * @param const unsigned int threadCount
             */
            Pool(const unsigned int threadCount);

            /**
             * Enqueue a task so it can be picked 
             * up by one of the available threads.
             * 
             * @param Thread::Handlers::TaskHandler handler
             * @return void
             */
            void enqueue(Handlers::TaskHandler handler) override;

        private:

            /**
             * The threads loop.
             * 
             * @return void
             */
            void start();

        private:
            
            /**
             * Store all threads.
             * 
             * @var std::vector<std::thread>
             */
            std::vector<std::thread> m_threads;

            /**
             * Store the mutex.
             * 
             * @var std::mutex
             */
            std::mutex m_mutex;

            /**
             * Store the queue.
             * 
             * @var std::queue<Handlers::TaskHandler>
             */
            std::queue<Handlers::TaskHandler> m_queue;

            /**
             * Determine if the pool is running.
             * 
             * @var std::atomic<bool>
             */
            std::atomic<bool> m_running;

            /**
             * Sleep the threads while there are no tasks.
             * 
             * @var std::atomic<bool>
             */
            std::condition_variable m_conditionVariable;

    };

}


#endif // THREAD_POOL_H
