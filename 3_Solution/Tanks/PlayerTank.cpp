#include "PlayerTank.h"
#include "Game.h"

extern Game* game;

PlayerTank::PlayerTank(const int& w, const int& h):iTank{w,h}
{
    health=3;

    setPixmap(QPixmap(":/images/playerTank.png"));
    center=boundingRect().center();
    origin=QPointF(center.x(), center.y());
    setTransformOriginPoint(origin);



    bulletSound=new QMediaPlayer();
    bulletSound->setSource(QUrl("qrc:/sounds/gunshot"));
}

PlayerTank::~PlayerTank()
{
    game->isOver=true;
    game->checkGameOver();
}

void PlayerTank::setBulletPos(iBullet* bullet)
{
    if(rotation==0){
        bullet->setPos(x() + (boundingRect().width()/2) - 4 , y() + boundingRect().height());  //22 120
    }

    else if(rotation==180){
        bullet->setPos(x() + (boundingRect().width()/2) - 2 , y() - 15); // 24 -10
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

void PlayerTank::checkColliding(QString direction)
{
    QList<QGraphicsItem*> colliding_items=collidingItems();
    for(auto a:colliding_items){

        if( typeid(*(a))==typeid(LightTank) || typeid(*(a))==typeid(MediumTank) || typeid(*(a))==typeid(HeavyTank) || typeid(*(a))==typeid(SuperHeavyTank)|| typeid(*(a))==typeid(PlayerTankSecond) || typeid(*(a))==typeid(PlayerTankFirst) || typeid(*(a))==typeid(Base) || typeid(*(a))==typeid(IndestructibleObject) || typeid(*(a))==typeid(NormalObject) || typeid(*(a))==typeid(Score) || typeid(*(a))==typeid(Health)){

            positionWhenColliding(direction);

            return;
        }
    }
}
