#ifndef DATAOBJECT_H
#define DATAOBJECT_H

#include <QXmlStreamReader>

class DataObject
{
private:
    QString m_name;
    QString m_type;
    QString m_transient;
    QString m_presCond;

public:
    DataObject();
    explicit DataObject(QXmlStreamReader& reader);
    QString name() const;
    QString type() const;
    QString transient() const;
    QString presCond() const;
};


#endif // DATAOBJECT_H
