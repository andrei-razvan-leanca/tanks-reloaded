#include "HeavyTank.h"

HeavyTank::HeavyTank(const int& w,const int& h):BotTank{w,h}
{
    health=5;
    setPixmap(QPixmap(":/images/heavyTank.png"));
    initializeBot();
}

HeavyTank::~HeavyTank()
{

}

void HeavyTank::setBulletPos(iBullet* bullet)
{
    if(rotation==0){
        bullet->setPos(x() + (boundingRect().width()/2) - 4 , y() + boundingRect().height() + 20);  //22 120
    }

    else if(rotation==180){
        bullet->setPos(x() + (boundingRect().width()/2) - 2 , y() - 40); // 24 -10
    }

    else if(rotation==270){
        bullet->setPos(x() + (boundingRect().width())*2 - 4, y() + (boundingRect().height()/2) - 6); // 90 58
    }

    else{
        bullet->setPos(x() - boundingRect().width() , y() + (boundingRect().height()/2) - 8); // 50 58
    }

    if(checkBush){
        bullet->setOpacity(0);
    }

    scene()->addItem(bullet);
}
