#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <algorithm>
#include <cstring>

class XMLEntryList;
class XMLEntry
{
    std::string m_entryName;
    std::string m_entryValue;
    bool m_hashed;
    public:
        XMLEntryList* m_parent;
        XMLEntry(std::string p_name, std::string p_value);
        std::string getValue();
        std::string getName();
        void setHash(bool p_hashEntry);
        bool hasHash();
        friend std::ostream& operator<<(std::ostream& p_out, XMLEntry& p_entry);
        XMLEntry& operator=(int p_value);
        XMLEntry& operator=(double p_value);
        XMLEntry& operator=(std::string p_value);
        XMLEntry& operator=(char p_value);
        bool operator==(XMLEntry p_entry);
        bool operator!=(XMLEntry p_entry);
};