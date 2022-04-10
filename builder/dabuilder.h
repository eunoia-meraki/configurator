#ifndef DABUILDER_H
#define DABUILDER_H

#include "builder.h"

class DaBuilder : public Builder
{
public:
    DaBuilder();
    virtual ~DaBuilder();
    virtual TreeItem* buildFromXml(QXmlStreamReader& reader) const override;
    TreeItem* buildFromNsd(const DataAttribute& dataAttribute) const;
};

#endif // DABUILDER_H
