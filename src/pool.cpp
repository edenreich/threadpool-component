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
 * Cleanup Destructor
 */
Pool::~Pool()
{
    for (auto & t : m_threads)
    {
        if (t.joinable())
            t.join();
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

    lock.unlock();

    m_conditionVariable.notify_one();
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

        m_conditionVariable.wait(lock, [this]() {
            return m_queue.size();
        });

        Handlers::TaskHandler task = m_queue.front();

        m_queue.pop();

        lock.unlock();

        task(std::this_thread::get_id());
        
    } while (m_running);
}

/**
 * Shutdown the thread pool.
 * 
 * @return void
 */
void Pool::shutdown()
{
    m_running = false;

    m_conditionVariable.notify_all();

    delete this;
}