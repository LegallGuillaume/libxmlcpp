#include "../headers/xmlentry.h"
#include <sstream>

XMLEntry::XMLEntry(std::string p_name, std::string p_value) :
m_entryName(p_name), m_entryValue(p_value), m_hashed(false)
{
    m_parent == nullptr;
}

std::string XMLEntry::getValue()
{
    return m_entryValue;
}

std::string XMLEntry::getName()
{
    return m_entryName;
}
void XMLEntry::setHash(bool p_hashEntry) 
{
    m_hashed = p_hashEntry;
}

bool XMLEntry::hasHash()
{
    return m_hashed;
}

std::ostream& operator<<(std::ostream& p_out, XMLEntry& p_entry)
{  
    p_out << p_entry.getValue();
    return p_out;
}

XMLEntry& XMLEntry::operator=(int p_value)
{
    std::stringstream ss;
    ss << p_value;
    m_entryValue = ss.str();
    return *this;
}

XMLEntry& XMLEntry::operator=(double p_value)
{
    std::stringstream ss;
    ss << p_value;
    m_entryValue = ss.str();
    return *this;
}

XMLEntry& XMLEntry::operator=(std::string p_value)
{
    m_entryValue = p_value;
    return *this;
}

XMLEntry& XMLEntry::operator=(char p_value)
{
    std::stringstream ss;
    ss << p_value;
    m_entryValue = ss.str();
    return *this;
}

bool XMLEntry::operator==(XMLEntry p_entry)
{
    return (p_entry.getValue() == getValue() && 
            p_entry.getName() == getName() );
}
bool XMLEntry::operator!=(XMLEntry p_entry)
{
    return (p_entry.getValue() != getValue() || 
            p_entry.getName() != getName() );
}