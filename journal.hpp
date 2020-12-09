#ifndef JOURNAL_H
#define JOURNAL_H

#include "memento.hpp"

#include <string>
#include <deque>
#include <map>

class Journal
{
    friend class PersistenceManager;
    
    const int maxStackSize = 30;
    std::string journalName;
    std::map<int, std::string> notes;
    std::deque<std::shared_ptr<Memento>> undo_stack;
    std::deque<std::shared_ptr<Memento>> redo_stack;
public:
    void addEntry(std::string ent, int i);
    void removeEntry(int i);
    void undo();
    void redo();
    Journal();
    Journal(const std::string &journalName);
    Journal(std::string &&journalName);
    Journal(const Journal &journal);
    Journal(Journal &&journal);
    Journal &operator=(const Journal &) = delete;
};

#endif