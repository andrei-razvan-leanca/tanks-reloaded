#include "IndestructibleObject.h"

IndestructibleObject::IndestructibleObject(const qreal x,const qreal y): iObject{x,y}
{
    setPixmap(QPixmap(":/images/stoneWall.jpg"));
}

IndestructibleObject::~IndestructibleObject()
{

}
