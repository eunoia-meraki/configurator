#include "dataattribute.h"

DataAttribute::DataAttribute() {}

DataAttribute::DataAttribute(QXmlStreamReader& reader)
{
    m_name = reader.attributes().value("name").toString();
    m_fc = reader.attributes().value("fc").toString();
    m_type = reader.attributes().value("type").toString();
    m_typeKind = reader.attributes().value("typeKind").toString();
    m_dchg = reader.attributes().value("dchg").toString();
    m_qchg = reader.attributes().value("qchg").toString();
    m_dupd = reader.attributes().value("dupd").toString();
    m_presCond = reader.attributes().value("presCond").toString();
}

QString DataAttribute::name() const
{
    return m_name;
}

QString DataAttribute::fc() const
{
    return m_fc;
}

QString DataAttribute::type() const
{
    return m_type;
}

QString DataAttribute::typeKind() const
{
    return m_typeKind;
}

QString DataAttribute::dchg() const
{
    return m_dchg;
}

QString DataAttribute::qchg() const
{
    return m_qchg;
}

QString DataAttribute::dupd() const
{
    return m_dupd;
}

QString DataAttribute::presCond() const
{
    return m_presCond;
}
