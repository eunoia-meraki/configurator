#include "nsdreader.h"

NsdReader::NsdReader(NsdData* data)
{
    m_data = data;
}

void NsdReader::read(QIODevice* device)
{
    m_nsd.setDevice(device);

    m_readUntil("NS");

    QString id = m_nsd.attributes().value("id").toString();

    if (id == QLatin1String("IEC 61850-7-4"))
    {
        m_readNsd74();
    }
    else if (id == QLatin1String("IEC 61850-7-3"))
    {
        m_readNsd73();
    }
    else if (id == QLatin1String("IEC 61850-7-2"))
    {
        m_readNsd72();
    }
}

void NsdReader::m_readNsd74()
{
    m_readUntil("Enumerations");

    m_readEnumerations();

    m_readUntil("LNClasses");

    QHash<QString, AbstractLnClass> abstractLnClasses;

    while (m_nsd.readNextStartElement())
    {
        if (m_nsd.name() == QLatin1String("AbstractLNClass"))
        {
            AbstractLnClass abstractLnClass(m_nsd);

            abstractLnClasses.insert(abstractLnClass.name(), abstractLnClass);
        }
        else if (m_nsd.name() == QLatin1String("LNClass"))
        {
            LnClass lnClass(m_nsd, abstractLnClasses);

            m_data->insert(lnClass);

            break;
        }
        else
            m_nsd.skipCurrentElement();
    }

    while (m_nsd.readNextStartElement())
    {
        if (m_nsd.name() == QLatin1String("LNClass"))
        {
            LnClass lnClass(m_nsd, abstractLnClasses);

            m_data->insert(lnClass);
        }
        else
            m_nsd.skipCurrentElement();
    }
}

void NsdReader::m_readNsd73()
{
    m_readUntil("Enumerations");

    m_readEnumerations();

    m_readUntil("ConstructedAttributes");

    m_readConstructedAttributes();

    m_readUntil("CDCs");

    while (m_nsd.readNextStartElement())
    {
        if (m_nsd.name() == QLatin1String("CDC"))
        {
            Cdc cdc(m_nsd);

            m_data->insert(cdc);
        }
        else
            m_nsd.skipCurrentElement();
    }
}

void NsdReader::m_readNsd72()
{
    m_readUntil("Enumerations");

    m_readEnumerations();

    m_readUntil("ConstructedAttributes");

    m_readConstructedAttributes();
}

void NsdReader::m_readEnumerations()
{
    while (m_nsd.readNextStartElement())
    {
        if (m_nsd.name() == QLatin1String("Enumeration"))
        {
            Enumeration enumeration(m_nsd);

            m_data->insert(enumeration);

        }
        else
            m_nsd.skipCurrentElement();
    }
}

void NsdReader::m_readConstructedAttributes()
{
    while (m_nsd.readNextStartElement())
    {
        if (m_nsd.name() == QLatin1String("ConstructedAttribute"))
        {
            ConstructedAttribute constructedAttribute(m_nsd);

            m_data->insert(constructedAttribute);

        }
        else
            m_nsd.skipCurrentElement();
    }
}

void NsdReader::m_readUntil(const char* elementName)
{
    while (m_nsd.name() != QLatin1String(elementName))
    {
        m_nsd.readNext();
    }
}
