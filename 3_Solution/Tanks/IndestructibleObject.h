#ifndef INDESTRUCTIBLEOBJECT_H
#define INDESTRUCTIBLEOBJECT_H

#include "iObject.h"

class IndestructibleObject : public iObject
{
public:
    IndestructibleObject(const qreal x, const qreal y);
    ~IndestructibleObject();
};

#endif // INDESTRUCTIBLEOBJECT_H
