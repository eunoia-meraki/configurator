#include "enumeration.h"

Enumeration::Enumeration() {}

Enumeration::Enumeration(QXmlStreamReader& reader)
{
    m_name = reader.attributes().value("name").toString();

    while (reader.readNextStartElement())
    {
        if (reader.name() == QLatin1String("Literal"))
        {
            Literal literal(reader);

            m_literals.append(literal);

            reader.skipCurrentElement();
        }
        else
            reader.skipCurrentElement();
    }
}

QString Enumeration::name() const
{
    return m_name;
}

const QVector<Literal>& Enumeration::literals() const
{
    return m_literals;
}
