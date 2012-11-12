#pragma once

#include "bunsan/service.hpp"

#include <mutex>
#include <condition_variable>

namespace bunsan
{
    class pseudo_service: virtual public service
    {
    public:
        pseudo_service();

        void start() override;
        void join() override;
        void stop() override;
        bool is_running() override;
        ~pseudo_service() override;

    private:
        typedef std::unique_lock<std::mutex> guard;

        std::mutex m_run_lock;
        bool m_running;
        std::condition_variable m_joiner;
    };
}
