#ifndef MEMENTO_H
#define MEMENTO_H

#include <utility>
#include <string>
#include <map>
#include <memory>


class Memento
{
public:
    virtual std::shared_ptr<Memento> undo() = 0;
    virtual ~Memento();
};

class DelMemento : public Memento
{
    typedef std::pair<int, std::string> jEntry;
    jEntry entry;
    std::map<int, std::string> &Jmap;

public:
    virtual std::shared_ptr<Memento> undo() override;
    DelMemento(std::map<int, std::string> &Jmap, const jEntry &entry);
};

class InsMemento : public Memento
{
    typedef std::pair<int, std::string> jEntry;
    jEntry entry;
    std::map<int, std::string> &Jmap;

public:
    virtual std::shared_ptr<Memento> undo() override;
    InsMemento(std::map<int, std::string> &Jmap, const jEntry &entry);
};
#endif