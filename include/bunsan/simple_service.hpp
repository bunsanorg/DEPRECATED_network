#pragma once

namespace bunsan
{
    class simple_service
    {
    public:
        virtual void join()=0;
        virtual void stop()=0;

        virtual inline ~simple_service() {}
    };
}
