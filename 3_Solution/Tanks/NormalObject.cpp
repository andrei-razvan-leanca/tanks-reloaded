#include "NormalObject.h"

NormalObject::NormalObject(const qreal x,const  qreal y): iObject{x,y}
{
    setPixmap(QPixmap(":/images/normalWall.jpg"));
}

NormalObject::~NormalObject()
{

}
