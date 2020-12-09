#include "persistance_manager.hpp"

#include <fstream>

std::string PersistenceManager::separator = "-:";

void PersistenceManager::saveJournal(std::shared_ptr<Journal> journal, const std::string &f)
{
    std::ofstream outFile(f);
    for (const auto &e : journal->notes)
    {
        outFile << e.first
                << separator
                << e.second << std::endl;
    }
}

std::shared_ptr<Journal> PersistenceManager::loadJournal(const std::string &f)
{
    auto outJournal = std::make_shared<Journal>();
    std::ifstream inFile(f);
    if (inFile.is_open())
    {
        std::string line;
        while (inFile >> line)
        {
            int pos = line.find_first_of(separator);
            int id = std::stoi(line.substr(0, pos));
            std::string note{line.begin() + pos + separator.length(), line.end()};
            outJournal->addEntry(note, id);
        }
    }
    return outJournal;
}