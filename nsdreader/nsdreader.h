#ifndef NSDREADER_H
#define NSDREADER_H

#include "nsddata.h"

class NsdReader
{
private:
    QXmlStreamReader m_nsd;
    NsdData* m_data;
    void m_readNsd74();
    void m_readNsd73();
    void m_readNsd72();
    void m_readEnumerations();
    void m_readConstructedAttributes();
    void m_readUntil(const char* elementName);

public:
    explicit NsdReader(NsdData* data);
    void read(QIODevice* device);
};

#endif // NSDREADER_H
