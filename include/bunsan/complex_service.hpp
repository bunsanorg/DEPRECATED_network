#pragma once

#include <vector>

#include <bunsan/service.hpp>

namespace bunsan
{
    class complex_service: virtual public service
    {
    public:
        void start() override;
        void join() override;
        void stop() override;
        bool is_running() override;
        ~complex_service() override;

    protected:
        typedef std::vector<service_ptr> container;

        container services;
    };
}
