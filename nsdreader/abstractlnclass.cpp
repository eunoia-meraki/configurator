#include "abstractlnclass.h"

AbstractLnClass::AbstractLnClass() {}

AbstractLnClass::AbstractLnClass(QXmlStreamReader& reader)
{
    m_name = reader.attributes().value("name").toString();
    m_base = reader.attributes().value("base").toString();

    while (reader.readNextStartElement())
    {
        if (reader.name() == QLatin1String("DataObject"))
        {
            DataObject dataObject(reader);

            m_dataObjects.append(dataObject);

            reader.skipCurrentElement();
        }
        else
            reader.skipCurrentElement();
    }
}

QString AbstractLnClass::name() const
{
    return m_name;
}

QString AbstractLnClass::base() const
{
    return m_base;
}

const QVector<DataObject>& AbstractLnClass::dataObjects() const
{
    return m_dataObjects;
}
