#pragma once

/* STDLIB */
#include <stack>
#include <memory>

class Command
{
    public:
        virtual ~Command() = default;
        virtual void execute() = 0;
        virtual void undo() = 0;
};

class CommandHistory
{
    public:
        std::stack<std::unique_ptr<Command>> command_stack;
};

extern CommandHistory cmd_history; // temporary