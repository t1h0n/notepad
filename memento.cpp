#include "memento.hpp"
#include <iostream>
Memento::~Memento() {}

DelMemento::DelMemento(std::map<int, std::string> &Jmap, const jEntry &entry) : Jmap(Jmap), entry(entry) {}

InsMemento::InsMemento(std::map<int, std::string> &Jmap, const jEntry &entry) : Jmap(Jmap), entry(entry) {}

std::shared_ptr<Memento> InsMemento::undo()
{
    std::cout<<"inserting: "<<entry.first<<"\n";
    Jmap.insert(entry);
    return std::make_shared<DelMemento>(Jmap, entry);
}

std::shared_ptr<Memento> DelMemento::undo()
{
    std::cout<<"deleting: "<<entry.first<<"\n";
    Jmap.erase(entry.first);
    return std::make_shared<InsMemento>(Jmap, entry);
}