#ifndef INDESTRUCTIBLEOBJECT_H
#define INDESTRUCTIBLEOBJECT_H

#include "iObject.h"

class IndestructibleObject : public iObject
{
public:
    IndestructibleObject(const qreal , const qreal );
    ~IndestructibleObject();
};

#endif // INDESTRUCTIBLEOBJECT_H
