#include <iostream>
#include <map>
#include <string>

#include "journal.hpp"
#include "persistance_manager.hpp"
/*

class JournalManager
{
    std::shared_ptr<Journal> jornal;
    DoUndo modifier;
    void save(const std::string &f);
    void load(const std::string &f);

    void add(std::string entry);
    void remove(int id);
};
/**/

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
    PersistenceManager::saveJournal(j, "out.txt");
    /*std::string rule;
    while(std::cin>>rule){
        std::cout<<rule<<"\n";
        if(rule=="exit")break;
    }
    
    std::shared_ptr<Journal> j1 = PersistenceManager::loadJournal("out.txt");
    PersistenceManager::saveJournal(j1, "works.txt");*/
}