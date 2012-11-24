#include "bunsan/xmlrpc_service.hpp"

#include "bunsan/logging/legacy.hpp"

void bunsan::xmlrpc_service::run()
{
    server_ptr server_;
    {
        guard lk(m_slock);
        create_server();
        server_ = server;
    }
    server_->run();
    {
        guard lk(m_slock);
        server.reset();
    }
}

void bunsan::xmlrpc_service::start()
{
    server_ptr server_;
    {
        guard lk(m_slock);
        server_ = server;
    }
    if (server_)
    {
        server_->terminate();
        {
            guard lk(m_tlock);
            if (m_thread.joinable())
                m_thread.join();
        }
    }
    {
        guard lk(m_tlock);
        m_thread = std::thread(&bunsan::xmlrpc_service::run, this);
    }
}

void bunsan::xmlrpc_service::join()
{
    guard lk(m_tlock);
    if (m_thread.joinable())
        m_thread.join();
}

void bunsan::xmlrpc_service::stop()
{
    DLOG(trying to stop);
    server_ptr server_;
    {
        guard lk(m_slock);
        server_ = server;
    }
    if (server_)
        server_->terminate();
}

bool bunsan::xmlrpc_service::is_running()
{
    guard lk(m_slock);
    return static_cast<bool>(server);
}

bunsan::xmlrpc_service::~xmlrpc_service()
{
    DLOG(trying to destroy);
    stop();
    join();
}
