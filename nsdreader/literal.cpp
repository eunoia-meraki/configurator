#include "literal.h"

Literal::Literal() {}

Literal::Literal(QXmlStreamReader& reader)
{
    m_name = reader.attributes().value("name").toString();
    m_literalVal = reader.attributes().value("literalVal").toString();
}

QString Literal::name() const
{
    return m_name;
}

QString Literal::literalVal() const
{
    return m_literalVal;
}
