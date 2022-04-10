#ifndef LNCLASS_H
#define LNCLASS_H

#include "abstractlnclass.h"
#include "dataobject.h"
#include <QHash>

class LnClass
{
private:
    QString m_name;
    QVector<DataObject> m_dataObjects;

public:
    LnClass();
    explicit LnClass(QXmlStreamReader& reader, QHash<QString, AbstractLnClass>& abstractLnClasses);
    QString name() const;
    const QVector<DataObject>& dataObjects() const;
};


#endif // LNCLASS_H
