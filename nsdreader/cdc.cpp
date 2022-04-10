#include "cdc.h"

Cdc::Cdc() {}

Cdc::Cdc(QXmlStreamReader& reader)
{
    m_name = reader.attributes().value("name").toString();

    while (reader.readNextStartElement())
    {
        if (reader.name() == QLatin1String("DataAttribute"))
        {
            DataAttribute dataAttribute(reader);

            m_dataAttributes.append(dataAttribute);

            reader.skipCurrentElement();
        }
        else if (reader.name() == QLatin1String("SubDataObject"))
        {
            DataObject dataObject(reader);

            m_subDataObjects.append(dataObject);

            reader.skipCurrentElement();
        }
        else
            reader.skipCurrentElement();
    }
}

QString Cdc::name() const
{
    return m_name;
}

const QVector<DataObject>& Cdc::subDataObjects() const
{
    return m_subDataObjects;
}

const QVector<DataAttribute>& Cdc::dataAttributes() const
{
    return m_dataAttributes;
}
