#include "CamouflageObject.h"

CamouflageObject::CamouflageObject(const qreal x, const qreal y):iObject{x,y}
{
    setPixmap(QPixmap(":/images/grass.jpg"));
}

CamouflageObject::~CamouflageObject()
{

}
