#include "iObject.h"

iObject::iObject(const qreal x,const qreal y):xPos{x},yPos{y}
{
    setPos(xPos,yPos);

}

iObject::~iObject()
{

}
