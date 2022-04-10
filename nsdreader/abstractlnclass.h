#ifndef ABSTRACTLNCLASS_H
#define ABSTRACTLNCLASS_H

#include "dataobject.h"

class AbstractLnClass
{
private:
    QString m_name;
    QString m_base;
    QVector<DataObject> m_dataObjects;

public:
    AbstractLnClass();
    explicit AbstractLnClass(QXmlStreamReader& reader);
    QString name() const;
    QString base() const;
    const QVector<DataObject>& dataObjects() const;
};


#endif // ABSTRACTLNCLASS_H
