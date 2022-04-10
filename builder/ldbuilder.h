#ifndef LDBUILDER_H
#define LDBUILDER_H

#include "builder.h"

class LdBuilder : public Builder
{
public:
    LdBuilder();
    virtual ~LdBuilder();
    virtual TreeItem* buildFromXml(QXmlStreamReader& reader) const override;
};

#endif // LDBUILDER_H
