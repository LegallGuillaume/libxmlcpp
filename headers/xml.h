#include "xmlentrylist.h"

class XML
{
    std::map<std::string, XMLEntryList> m_entries;
    public:
        XML();
        ~XML();
        void read(std::string p_filename);
        void write(std::string p_filepath);
        XMLEntryList& operator[](std::string p_node);
        XML& operator-=(XMLEntryList& p_entrie);
        XML& operator-=(XMLEntry& p_entrie);
    private:
        std::string encrypt(const std::string& p_str);
        bool contain(std::string& p_1, std::string p_2);
        int espaceFind(std::string p_1);
        std::string parseLine(std::string& p_line);
        
};