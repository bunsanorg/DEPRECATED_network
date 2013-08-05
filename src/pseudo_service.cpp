#include <bunsan/pseudo_service.hpp>

bunsan::pseudo_service::pseudo_service(): m_running(false) {}

void bunsan::pseudo_service::start()
{
    guard lk(m_run_lock);
    m_running = true;
}

void bunsan::pseudo_service::join()
{
    guard lk(m_run_lock);
    m_joiner.wait(lk, [this](){return !m_running;});
}

void bunsan::pseudo_service::stop()
{
    guard lk(m_run_lock);
    m_running = false;
    m_joiner.notify_all();
}

bool bunsan::pseudo_service::is_running()
{
    guard lk(m_run_lock);
    return m_running;
}

bunsan::pseudo_service::~pseudo_service()
{
    stop();
}
