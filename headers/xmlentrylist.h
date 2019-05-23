#include "xmlentry.h"

class XMLEntryList
{
    std::list<XMLEntry> m_entries;
    public:
        std::string m_key;
        XMLEntryList();
        XMLEntryList(std::list<XMLEntry>& p_entries);
        void add(XMLEntry p_entry);
        void clear();
        size_t getSize();
        std::list<XMLEntry>& getList();
        XMLEntry& operator[](std::string p_entry);
        XMLEntryList& operator+(XMLEntry& p_entry);
        XMLEntryList& operator-(XMLEntry& p_entry);
        XMLEntryList& operator=(XMLEntryList p_entry);
        XMLEntryList& operator+=(XMLEntry& p_entry);
        XMLEntryList& operator-=(XMLEntry& p_entry);
        bool operator==(XMLEntryList& p_entry);
};