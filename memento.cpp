#include "memento.hpp"

Memento::~Memento() {}

DelMemento::DelMemento(std::map<int, std::string> &Jmap, const jEntry &entry) : Jmap(Jmap), entry(entry) {}

InsMemento::InsMemento(std::map<int, std::string> &Jmap, const jEntry &entry) : Jmap(Jmap), entry(entry) {}

std::shared_ptr<Memento> InsMemento::undo()
{
    Jmap.insert(entry);
    return std::make_shared<DelMemento>(Jmap, entry);
}

std::shared_ptr<Memento> DelMemento::undo()
{
    Jmap.erase(entry.first);
    return std::make_shared<InsMemento>(Jmap, entry);
}
