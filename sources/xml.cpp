#include "../headers/xml.h"
#include <fstream>

#define KEY_HASH "0ç'fkSLz$*ù"

XML::XML()
{}

XML::~XML()
{}

XMLEntryList& XML::operator[](std::string p_node)
{
    auto f = m_entries.find(p_node);
    m_entries[p_node].m_key = p_node;
    return m_entries[p_node];
}

bool XML::contain(std::string& p_1, std::string p_2)
{
    return (p_1.find(p_2) != std::string::npos);
}

int XML::espaceFind(std::string p_1)
{
    int idx=0;
    for(auto p=p_1.begin(); p!=p_1.end(); p++)
    {
        if((*p) != ' ')
            break;
        idx++;
    }
    return idx;
}

void XML::read(std::string p_filename)
{
    std::ifstream file;
    file.open(p_filename, std::ifstream::in);
    std::string txt;
    XMLEntryList entrylist;
    std::string node;
    while(std::getline(file, txt))
    {
        if(!txt.empty() && entrylist.getSize() == 0 && node.empty())
        {
            txt.erase(espaceFind(txt),1);
            txt.erase(txt.end()-1,txt.end());
            node = txt;
        }
        if(txt[0] == ' ' || txt[0] == '\t')
        {  
            txt.erase(0, espaceFind(txt));
            std::string n = parseLine(txt);
            bool iscript = false;
            if(txt[0] == (char)1)
            {
                iscript = true;
                txt = encrypt(txt);
            }
            XMLEntry entry(n, txt);
            entry.setHash(iscript);
            entrylist.add(entry);
        }
        std::string node_test = "</" + node + ">";
        if(contain(txt, node_test))
        {
            m_entries[node] = entrylist;
            entrylist.clear();
            node = "";
        }
    }
}

std::string XML::parseLine(std::string& p_line)
{
    std::string node;
    p_line.erase(0,1);
    int index;
    for(index=0; index < p_line.size(); index++)
    {
        if(p_line[index] != '>')
            node += p_line[index];
        else
            break;
    }
    p_line.erase(0,index+1);
    std::string endls = "</" + node + ">";
    p_line.erase(p_line.end()-endls.size(), p_line.end());
    return node;
}

void XML::write(std::string p_filepath)
{
    std::ofstream fil;
    fil.open(p_filepath, std::ios::out);
    for(auto p=m_entries.begin(); p != m_entries.end(); p++)
    {
        fil << "<" + p->first + ">" << std::endl;
        auto l = p->second.getList();
        for(auto q=l.begin(); q != l.end(); q++)
        {
            fil << "    <" + (*q).getName() + ">";
            if(q->hasHash())
            {
                fil << (char)1;
                fil << encrypt((*q).getValue());
            }
            else
                fil << (*q).getValue();
            fil << "</" + (*q).getName() + ">\n";
        }
        fil << "</" + p->first + ">" << std::endl << std::endl;
    }
    fil.close();
}

XML& XML::operator-=(XMLEntryList& p_entrie)
{
    auto f = m_entries.find(p_entrie.m_key);
    if(f != m_entries.end())
        m_entries.erase(f);
    return *this;
}

XML& XML::operator-=(XMLEntry& p_entrie)
{
    for(auto p=m_entries.begin(); p != m_entries.end(); p++)
    {
        auto l = p->second.getList();
        auto f = std::find(l.begin(), l.end(), p_entrie);
        if(f != l.end())
        {
            p->second -= p_entrie;
            break;
        }
    }
    return *this;
}


std::string XML::encrypt(const std::string& p_str)
{
    std::string out = p_str;
    if(p_str[0] == (char)1)
        out.erase(0,1); //remove \1
    std::string k = KEY_HASH;
    for(int i=0; i<out.size(); i++)
        out[i] = out[i] ^ k[i%k.size()];
    return out;
}