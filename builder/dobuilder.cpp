#include "dobuilder.h"

DoBuilder::DoBuilder() {}

DoBuilder::~DoBuilder() {}

TreeItem* DoBuilder::buildFromXml(QXmlStreamReader& reader) const
{
    DoItem* item = new DoItem();

    item->setName(reader.attributes().value("name").toString());
    item->setDesc(reader.attributes().value("desc").toString());
    item->setCdc(reader.attributes().value("cdc").toString());
    item->setPresCond(reader.attributes().value("presCond").toString());
    item->setChecked(reader.attributes().value("checked").toString());

    return item;
}

TreeItem* DoBuilder::buildFromNsd(const DataObject& dataObject) const
{
    DoItem* doItem = new DoItem();

    doItem->setName(dataObject.name());
    doItem->setCdc(dataObject.type());
    doItem->setPresCond(dataObject.presCond());

    if (dataObject.presCond() == QLatin1String("M"))
    {
        doItem->setChecked(true);
    }
    else
    {
        doItem->setChecked(false);
    }

    return doItem;
}
