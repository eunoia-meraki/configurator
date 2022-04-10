#ifndef DATAATTRIBUTE_H
#define DATAATTRIBUTE_H

#include <QXmlStreamReader>

class DataAttribute
{
private:
    QString m_name;
    QString m_fc;
    QString m_type;
    QString m_typeKind;
    QString m_dchg;
    QString m_qchg;
    QString m_dupd;
    QString m_presCond;

public:
    DataAttribute();
    explicit DataAttribute(QXmlStreamReader& reader);
    QString name() const;
    QString fc() const;
    QString type() const;
    QString typeKind() const;
    QString dchg() const;
    QString qchg() const;
    QString dupd() const;
    QString presCond() const;
};

#endif // DATAATTRIBUTE_H
