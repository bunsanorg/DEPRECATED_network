#pragma once

#include <bunsan/service.hpp>

#include <xmlrpc-c/server_abyss.hpp>
#include <xmlrpc-c/registry.hpp>
#include <xmlrpc-c/girerr.hpp>

#include <thread>
#include <mutex>

namespace bunsan
{
    class xmlrpc_service: virtual public service
    {
    public:
        void start() override;
        void join() override;
        void stop() override;
        bool is_running() override;
        ~xmlrpc_service() override;

    protected:
        typedef std::unique_lock<std::mutex> guard;
        typedef xmlrpc_c::registryPtr registry_ptr;
        typedef std::shared_ptr<xmlrpc_c::serverAbyss> server_ptr;

        virtual void create_server()=0;

    protected:
        server_ptr server;

    private:
        void run();

    private:
        std::thread m_thread;
        std::mutex m_slock, m_tlock;
    };
}
