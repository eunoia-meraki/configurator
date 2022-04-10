#include "dataobject.h"

DataObject::DataObject() {}

DataObject::DataObject(QXmlStreamReader& reader)
{
    m_name = reader.attributes().value("name").toString();
    m_type = reader.attributes().value("type").toString();
    m_transient = reader.attributes().value("transient").toString();
    m_presCond = reader.attributes().value("presCond").toString();
}

QString DataObject::name() const
{
    return m_name;
}

QString DataObject::type() const
{
    return m_type;
}

QString DataObject::transient() const
{
    return m_transient;
}

QString DataObject::presCond() const
{
    return m_presCond;
}
