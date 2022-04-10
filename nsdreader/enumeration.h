#ifndef ENUMERATION_H
#define ENUMERATION_H

#include "literal.h"

class Enumeration
{
private:
    QString m_name;
    QVector<Literal> m_literals;

public:
    Enumeration();
    explicit Enumeration(QXmlStreamReader& reader);
    QString name() const;
    const QVector<Literal>& literals() const;
};

#endif // ENUMERATION_H
