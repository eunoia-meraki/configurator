#include "nsddata.h"

NsdData::NsdData() {}

void NsdData::insert(const LnClass& lnClass)
{
    m_lnClasses.insert(lnClass.name(), lnClass);
}

const QHash<QString, LnClass>& NsdData::lnClasses() const
{
    return m_lnClasses;
}

void NsdData::insert(const Cdc& cdc)
{
    m_cdcs.insert(cdc.name(), cdc);
}

const QHash<QString, Cdc>& NsdData::cdcs()const
{
    return m_cdcs;
}

void NsdData::insert(const ConstructedAttribute& constructedAttribute)
{
    m_constructedAttributes.insert(constructedAttribute.name(), constructedAttribute);
}

const QHash<QString, ConstructedAttribute>& NsdData::constructedAttributes() const
{
    return m_constructedAttributes;
}

void NsdData::insert(const Enumeration& enumeration)
{
    m_enumerations.insert(enumeration.name(), enumeration);
}

const  QHash<QString, Enumeration>& NsdData::enumerations() const
{
    return m_enumerations;
}
