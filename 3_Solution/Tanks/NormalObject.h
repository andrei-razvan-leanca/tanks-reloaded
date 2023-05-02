#ifndef NORMALOBJECT_H
#define NORMALOBJECT_H

#include "iObject.h"

class NormalObject : public iObject
{
public:
    NormalObject(const qreal x, const qreal y);
    ~NormalObject();
};

#endif // NORMALOBJECT_H
