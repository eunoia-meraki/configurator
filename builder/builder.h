#ifndef BUILDER_H
#define BUILDER_H

#include "treeitem.h"
#include "nsdreader.h"

class Builder
{
public:
    Builder();
    virtual ~Builder();
    virtual TreeItem* buildFromXml(QXmlStreamReader& reader) const = 0;
};

#endif // BUILDER_H
