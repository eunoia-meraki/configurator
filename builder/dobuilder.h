#ifndef DOBUILDER_H
#define DOBUILDER_H

#include "builder.h"

class DoBuilder : public Builder
{
public:
    DoBuilder();
    virtual ~DoBuilder();
    virtual TreeItem* buildFromXml(QXmlStreamReader& reader) const override;
    TreeItem* buildFromNsd(const DataObject& dataObject) const;
};

#endif // DOBUILDER_H
