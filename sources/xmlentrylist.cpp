#include "../headers/xmlentrylist.h"

XMLEntryList::XMLEntryList(){}
XMLEntryList::XMLEntryList(std::list<XMLEntry>& p_entries)
{
    std::copy(p_entries.begin(), p_entries.end(), m_entries.begin());
}
void XMLEntryList::add(XMLEntry p_entry)
{
    p_entry.m_parent = this;
    m_entries.push_back(p_entry);
}
void XMLEntryList::clear() {m_entries.clear();}
size_t XMLEntryList::getSize() {return m_entries.size();}
std::list<XMLEntry>& XMLEntryList::getList(){return m_entries;}
XMLEntry& XMLEntryList::operator[](std::string p_entry)
{
    for(auto p=m_entries.begin(); p!= m_entries.end(); p++)
    {
        if((*p).getName() == p_entry)
            return (*p);
    }
    add(XMLEntry(p_entry, ""));
    return m_entries.back();
}
XMLEntryList& XMLEntryList::operator+(XMLEntry& p_entry)
{
    add(p_entry);
    return *this;
}
XMLEntryList& XMLEntryList::operator-(XMLEntry& p_entry)
{
    auto p = std::find(m_entries.begin(), m_entries.end(), p_entry);
    if(p != m_entries.end())
        m_entries.erase(p);
    return *this;
}
XMLEntryList& XMLEntryList::operator=(XMLEntryList p_entry)
{
    m_entries = p_entry.getList();
    return *this;
}
XMLEntryList& XMLEntryList::operator+=(XMLEntry& p_entry)
{
    *this = *this + p_entry;
    return *this;
}
XMLEntryList& XMLEntryList::operator-=(XMLEntry& p_entry)
{
    *this = *this - p_entry;
    return *this;
}
bool XMLEntryList::operator==(XMLEntryList& p_entry)
{
    auto l1 = m_entries;
    auto l2 = p_entry.getList();
    if(l1.size() != l2.size()) return false;

    auto p2 = l2.begin();
    for(auto p=l1.begin(); p != l1.end(); p++)
    {
        if(*p2 != *p)
            return false;
        p2++;
    }
    return true;
}