#include "journal.hpp"

void Journal::addEntry(std::string ent, int i)
{
    this->notes.emplace(i, ent);
    undo_stack.push_back(std::make_shared<DelMemento>(notes, std::make_pair(i, ent)));
}

void Journal::removeEntry(int i)
{
    auto pos = this->notes.find(i);
    if (pos != this->notes.end())
        undo_stack.push_back(std::make_shared<InsMemento>(notes, std::make_pair(i, pos->second)));
        notes.erase(pos);
    
}
void Journal::undo()
{
    if (!undo_stack.empty())
    {
        auto newMem = undo_stack.back()->undo();
        if(redo_stack.size()>maxStackSize)
            redo_stack.pop_front();
        redo_stack.push_back(newMem);
        undo_stack.pop_back();
    }
}
void Journal::redo()
{
    if (!redo_stack.empty())
    {
        auto newMem = redo_stack.back()->undo();
        if(undo_stack.size()>maxStackSize)
            undo_stack.pop_front();
        undo_stack.push_back(newMem);
        redo_stack.pop_back();
    }
}
Journal::Journal(const std::string &journalName) : journalName(journalName) {}

Journal::Journal(std::string &&journalName) : journalName(journalName) {}

Journal::Journal(const Journal &journal) : journalName(journal.journalName), notes(journal.notes) {}

Journal::Journal(Journal &&journal) : journalName(journal.journalName), notes(journal.notes) {}

Journal::Journal() {}