#pragma once

class Tool
{
    public:
        virtual void on_press() = 0;
        virtual void on_hold() = 0;
        virtual void on_release() = 0;
        virtual ~Tool() = default;
};