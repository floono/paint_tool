#pragma once

class Command
{
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~Command() = default;
};

class CommandHistory
{

};