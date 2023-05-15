#include "MediumTank.h"

MediumTank::MediumTank(const int& w, const int& h):BotTank{w,h}
{
    health=3;
    setPixmap(QPixmap(":/images/mediumTank.png"));
    initializeBot();
}

MediumTank::~MediumTank()
{

}

void MediumTank::setBulletPos(iBullet* bullet)
{
    if(rotation==0){
        bullet->setPos(x() + (boundingRect().width()/2) - 2, y() + boundingRect().height() + 10);  //22 120
    }

    else if(rotation==180){
        bullet->setPos(x() + (boundingRect().width()/2) - 3 , y() - 40); // 24 -10
    }

    else if(rotation==270){
        bullet->setPos(x() + (boundingRect().width())*2 , y() + (boundingRect().height()/2) - 8); // 90 58
    }

    else{
        bullet->setPos(x() - boundingRect().width() , y() + (boundingRect().height()/2) - 6); // 50 58
    }

    if(checkBush){
        bullet->setOpacity(0);
    }

    scene()->addItem(bullet);
}
