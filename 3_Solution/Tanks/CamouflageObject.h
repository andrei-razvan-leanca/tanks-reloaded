#ifndef CAMOUFLAGEOBJECT_H
#define CAMOUFLAGEOBJECT_H

#include "iObject.h"

class CamouflageObject : public iObject
{
public:
    CamouflageObject(const qreal x,const qreal y);
    ~CamouflageObject();
};

#endif // CAMOUFLAGEOBJECT_H
