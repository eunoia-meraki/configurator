#include "dabuilder.h"

DaBuilder::DaBuilder() {}

DaBuilder::~DaBuilder() {}

TreeItem* DaBuilder::buildFromXml(QXmlStreamReader& reader) const
{
    DaItem* item = new DaItem();

    item->setName(reader.attributes().value("name").toString());
    item->setFc(reader.attributes().value("fc").toString());
    item->setDchg(reader.attributes().value("dchg").toString());
    item->setQchg(reader.attributes().value("qchg").toString());
    item->setDupd(reader.attributes().value("dupd").toString());
    item->setPresCond(reader.attributes().value("presCond").toString());
    item->setChecked(reader.attributes().value("checked").toString());

    ///!!!добавил
    item->setType(reader.attributes().value("bType").toString());
    item->setEvent(reader.attributes().value("event").toString());

    return item;
}

TreeItem* DaBuilder::buildFromNsd(const DataAttribute& dataAttribute) const
{
    DaItem* daItem = new DaItem();

    daItem->setName(dataAttribute.name());
    daItem->setFc(dataAttribute.fc());
    daItem->setDchg(dataAttribute.dchg());
    daItem->setQchg(dataAttribute.qchg());
    daItem->setDupd(dataAttribute.dupd());
    daItem->setPresCond(dataAttribute.presCond());

    if (dataAttribute.presCond() == QLatin1String("M"))
    {
        daItem->setChecked(true);
    }
    else
    {
        daItem->setChecked(false);
    }

    return daItem;
}
