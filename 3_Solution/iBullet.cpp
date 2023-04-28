#include "iBullet.h"

iBullet::iBullet(const int& rotation):r{rotation}
{
    widthBullet=10;
    heightBullet=20;
    setPixmap(QPixmap(":/images/bullet.png"));

    //qDebug()<<"widthBullet: "<<boundingRect().width()<<"heightBullet: "<< boundingRect().height();
    setDirection(rotation);
    center=boundingRect().center();
    origin=QPointF(center.x(), center.y());
    setTransformOriginPoint(origin);

}

iBullet::~iBullet()
{

}

void iBullet::setDirection(const int& rotation)
{
    setRotation(r);

    if(rotation==0){
        left=0;
        right=0;
        up=0;
        down=1;

    }
    else if(rotation==180){
        left=0;
        right=0;
        up=1;
        down=0;

    }

    else if(rotation==270){
        left=0;
        right=1;
        up=0;
        down=0;

    }

    else{
        left=1;
        right=0;
        up=0;
        down=0;

    }
}
