#ifndef CONSTRUCTEDATTRIBUTE_H
#define CONSTRUCTEDATTRIBUTE_H

#include "dataattribute.h"

class ConstructedAttribute
{
private:
    QString m_name;
    QVector<DataAttribute> m_subDataAttributes;

public:
    ConstructedAttribute();
    explicit ConstructedAttribute(QXmlStreamReader& reader);
    QString name() const;
    const QVector<DataAttribute>& subDataAttributes() const;
};

#endif // CONSTRUCTEDATTRIBUTE_H
