#ifndef LNBUILDER_H
#define LNBUILDER_H

#include "builder.h"

class LnBuilder : public Builder
{
public:
    LnBuilder();
    virtual ~LnBuilder();
    virtual TreeItem* buildFromXml(QXmlStreamReader& reader) const override;
};

#endif // LNBUILDER_H
