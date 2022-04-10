#ifndef LITERAL_H
#define LITERAL_H

#include <QXmlStreamReader>

class Literal
{
    QString m_name;
    QString m_literalVal;

public:
    Literal();
    explicit Literal(QXmlStreamReader& reader);
    QString name() const;
    QString literalVal() const;
};

#endif // LITERAL_H
