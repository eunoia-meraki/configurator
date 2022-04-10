#ifndef NSDDATA_H
#define NSDDATA_H

#include "lnclass.h"
#include "cdc.h"
#include "constructedattribute.h"
#include "enumeration.h"

class NsdData
{
private:
    QHash<QString, LnClass> m_lnClasses;
    QHash<QString, Cdc> m_cdcs;
    QHash<QString, ConstructedAttribute> m_constructedAttributes;
    QHash<QString, Enumeration> m_enumerations;

public:
    NsdData();
    void insert(const LnClass& lnClass);
    const QHash<QString, LnClass>& lnClasses() const;
    void insert(const Cdc& cdc);
    const QHash<QString, Cdc>& cdcs() const;
    void insert(const ConstructedAttribute& constructedAttribute);
    const QHash<QString, ConstructedAttribute>& constructedAttributes() const;
    void insert(const Enumeration& enumeration);
    const QHash<QString, Enumeration>& enumerations() const;
};


#endif // NSDDATA_H
