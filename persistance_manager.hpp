#ifndef PERSISTENCE_MANAGER_H
#define PERSISTENCE_MANAGER_H

#include "journal.hpp"

#include <string>
#include <memory>

class PersistenceManager
{
    static std::string separator;

public:
    static void saveJournal(std::shared_ptr<Journal> journal, const std::string &f);
    static std::shared_ptr<Journal> loadJournal(const std::string &f);
};

#endif