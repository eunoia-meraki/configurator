#ifndef CDC_H
#define CDC_H

#include "dataattribute.h"
#include "dataobject.h"

class Cdc
{
private:
    QString m_name;
    QVector<DataObject> m_subDataObjects;
    QVector<DataAttribute> m_dataAttributes;

public:
    Cdc();
    explicit Cdc(QXmlStreamReader& reader);
    QString name() const;
    const QVector<DataObject>& subDataObjects() const;
    const QVector<DataAttribute>& dataAttributes() const;
};

#endif // CDC_H
