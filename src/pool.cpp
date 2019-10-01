#include "include/thread/pool.h"

using namespace Thread;


/**
 * Constructor
 */
Pool::Pool(const unsigned int threadCount) : m_running(true)
{
    for (unsigned int index = 0; index < threadCount; index++)
    {
        m_threads.emplace_back(::std::thread(&Pool::start, this));
    }
}

/**
 * Enqueue a task so it can be picked 
 * up by one of the available threads.
 * 
 * @param Thread::Handlers::TaskHandler handler
 * @return void
 */
void Pool::enqueue(Handlers::TaskHandler handler)
{
    std::unique_lock<std::mutex> lock(m_mutex);
    
    m_queue.push(handler);
    m_conditionVariable.notify_one();

    lock.unlock();
}

/**
 * The threads loop.
 * 
 * @return void
 */
void Pool::start()
{
    do
    {
        std::unique_lock<std::mutex> lock(m_mutex);

        m_conditionVariable.wait(lock, [&]() {
            return !m_queue.empty();
        });

        Handlers::TaskHandler task = m_queue.front();

        task(std::this_thread::get_id());

        m_queue.pop();

        lock.unlock();
        
    } while (m_running);
}