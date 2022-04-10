#include "lnclass.h"

LnClass::LnClass() {}

LnClass::LnClass(QXmlStreamReader& reader, QHash<QString, AbstractLnClass>& abstractLnClasses)
{
    m_name = reader.attributes().value("name").toString();

    QVector<QString> bases;
    bases.append(reader.attributes().value("base").toString());

    while (bases.last() != "")
    {
        bases.append(abstractLnClasses.value(bases.last()).base());
    }

    bases.pop_back();

    for (QVector<QString>::reverse_iterator i = bases.rbegin(); i < bases.rend(); i++)
    {
        m_dataObjects += abstractLnClasses.value(*i).dataObjects();
    }

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

QString LnClass::name() const
{
    return m_name;
}

const QVector<DataObject>& LnClass::dataObjects() const
{
    return m_dataObjects;
}
