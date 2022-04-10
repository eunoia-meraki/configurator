#include "lnbuilder.h"

LnBuilder::LnBuilder() {}

LnBuilder::~LnBuilder() {}

TreeItem* LnBuilder::buildFromXml(QXmlStreamReader& reader) const
{
    LnItem* item = new LnItem();

    item->setLnClass(reader.attributes().value("lnClass").toString());
    item->setDesc(reader.attributes().value("desc").toString());

    return item;
}
