#include "ldbuilder.h"

LdBuilder::LdBuilder() {}

LdBuilder::~LdBuilder() {}

TreeItem* LdBuilder::buildFromXml(QXmlStreamReader& reader) const
{
    LdItem* item = new LdItem();

    item->setName(reader.attributes().value("inst").toString());
    item->setDesc(reader.attributes().value("desc").toString());

    return item;
}
