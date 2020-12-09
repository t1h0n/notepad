#ifndef COMMAND_H
#define COMMAND_H
#include "memento.hpp"
template <typename T>
class Command
{
    T obj;
    Memento<T> memento;
    public:
    virtual void execute() = 0;
    virtual void unexecute() = 0;
    virtual ~Command();
};
#endif