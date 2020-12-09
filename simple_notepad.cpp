#include <iostream>
#include <map>
#include <string>

#include "journal.hpp"
#include "persistance_manager.hpp"

int main()
{
    Journal j1{"ent"};
    Journal j3{j1};
    Journal j4{std::move(j1)};
    
    std::shared_ptr<Journal> j{new Journal()};
    j->addEntry("1", 123);
    j->addEntry("2", 124);
    
    j->undo();
    j->addEntry("3", 150);
    
    j->undo();
    j->redo();
    PersistenceManager::saveJournal(j, "out.txt");

}
