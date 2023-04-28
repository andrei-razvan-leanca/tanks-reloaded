#include "PlayerBullet.h"
#include "BotTank.h"
#include "Game.h"

extern Game* game;

PlayerBullet::PlayerBullet(const int& rotation): iBullet{rotation}
{
    QTimer* time=new QTimer();
    connect(time,SIGNAL(timeout()),this,SLOT(move()));

    time->start(50);
}

PlayerBullet::~PlayerBullet()
{

}

void PlayerBullet::move()
{
    //if bullet collides with enemy, destroy both
    QList<QGraphicsItem*> colliding_items=collidingItems();

    for(auto a:colliding_items){
        if(typeid(*(a))==typeid(BotTank)){
            game->score->increase();

            scene()->removeItem(a);
            scene()->removeItem(this);

            delete a;
            delete this;

            game->addBotTank();

            return;
        }
    }
    //qDebug()<<"pos: "<<x()<<"  "<< y();
    //move bullet
    if(up){
        setPos(x(),y()-10);
        if(y() <0){
            scene()->removeItem(this);
            delete this;
        }
    }

    else if(down){
        setPos(x(), y()+10);
        if(y() > game->playerTank->getHeight()){
            scene()->removeItem(this);
            delete this;
        }
    }

    else if(right){
        setPos(x()+10, y());
        if(x() > game->playerTank->getWidth()){
            scene()->removeItem(this);
            delete this;
        }
    }

    else {
        setPos(x()-10, y());
        if(x() < 0){
            scene()->removeItem(this);
            delete this;
        }
    }
}
