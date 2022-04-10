#include "constructedattribute.h"

ConstructedAttribute::ConstructedAttribute() {}

ConstructedAttribute::ConstructedAttribute(QXmlStreamReader& reader)
{
    m_name = reader.attributes().value("name").toString();

    while (reader.readNextStartElement())
    {
        if (reader.name() == QLatin1String("SubDataAttribute"))
        {
            DataAttribute subDataAttribute(reader);

            m_subDataAttributes.append(subDataAttribute);

            reader.skipCurrentElement();
        }
        else
            reader.skipCurrentElement();
    }
}

QString ConstructedAttribute::name() const
{
    return m_name;
}

const QVector<DataAttribute>& ConstructedAttribute::subDataAttributes() const
{
    return m_subDataAttributes;
}
