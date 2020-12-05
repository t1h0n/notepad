//class journal
// percistance_manager save/ load
// do/ undo stack (insertion/deletion) = insertion done by deleting the id of the last item; deletion done 
#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <memory>
#include <fstream>

struct Journal{
    typedef int id;
    typedef std::string entry;

    std::string journalName;
    std::map<id, entry> notes;

    void addEntry(entry ent, id i);
    void removeEntry(id i);
    Journal()=default;
    Journal(const std::string& journalName);
    Journal(const Journal& journal);
    Journal(Journal&& journal);
};

void Journal::addEntry(Journal::entry entry, Journal::id id){
    notes.emplace(id, entry);
}
void Journal::removeEntry(Journal::id id){
    notes.erase(id);
}

Journal::Journal(const std::string& journalName):journalName(journalName){}
Journal::Journal(const Journal& journal):journalName(journal.journalName){}
Journal::Journal(Journal&& journal){
    notes=std::move(journal.notes);
}

struct PersistenceManager{
    static std::string separator;
    static void saveJournal(std::shared_ptr<Journal> journal, const std::string& f);
    static std::shared_ptr<Journal> loadJournal(const std::string& f);
};
std::string PersistenceManager::separator=": ";

void PersistenceManager::saveJournal(std::shared_ptr<Journal> journal, const std::string& f){
    std::ofstream outFile(f);
    for(const auto& [id, entry]: journal->notes){
        outFile <<id
                <<separator
                <<entry<<std::endl;
    }
}

std::shared_ptr<Journal> PersistenceManager::loadJournal(const std::string& f){
    std::shared_ptr<Journal> outJournal;
    std::ifstream inFile(f);
    if (inFile.is_open()){
        std::cout<<"open\n";
        std::string line;
        while(inFile>>line){
            std::cout<<line;
            int pos = line.find_first_of(separator);
            Journal::id id = stoi(line.substr(0, pos));
            Journal::entry note{line.begin()+pos+separator.length(), line.end()};
            outJournal->addEntry(note, id);
        }
    }
    return outJournal;
}

class DoUndo{
    std::queue<std::pair<int, std::string>> _doStack;
    std::queue<std::pair<int, std::string>> _undoStack;
    std::shared_ptr<Journal> jornal;
    DoUndo(std::shared_ptr<Journal> j);
    void _do();
    void _undo();
};

class JournalManager{
    std::shared_ptr<Journal> jornal;
    DoUndo modifier;
    void save(const std::string& f);
    void load(const std::string& f);
    
    void add(Journal::entry entry);
    void remove(Journal::id id);
};

int main(){
    std::shared_ptr<Journal> j;
    j->addEntry("ne budu", 123);
    PersistenceManager::saveJournal(j, "out.txt");
    std::cout<<"hello";
}