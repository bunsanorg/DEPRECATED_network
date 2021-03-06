#pragma once

#include <memory>

namespace bunsan
{
    class service
    {
    public:
        /*!
         * \brief start service
         *
         * non-blocking call, service will run in different thread
         *
         * if service was started before, it will do restart
         */
        virtual void start()=0;

        /// join service thread
        virtual void join()=0;

        /*!
         * \brief stop service
         *
         * non-blocking call, service will continue execution, but soon should do clean-up actions and stop.
         */
        virtual void stop()=0;

        /// \return whether service is running
        virtual bool is_running()=0;

        virtual inline ~service(){}
    };
    typedef std::shared_ptr<service> service_ptr;
}
