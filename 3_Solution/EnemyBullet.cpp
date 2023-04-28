#include "EnemyBullet.h"
#include"PlayerTank.h"
#include "Game.h"

extern Game* game;

EnemyBullet::EnemyBullet(const int& rotation): iBullet{rotation}
{
    QTimer* time=new QTimer();
    connect(time,SIGNAL(timeout()),this,SLOT(move()));



    time->start(50);
}

EnemyBullet::~EnemyBullet()
{

}

void EnemyBullet::move()
{
    //if bullet collides with player, destroy both
    QList<QGraphicsItem*> colliding_items=collidingItems();

    for(auto a:colliding_items){
        if(typeid(*(a))==typeid(PlayerTank)){
            game->health->decrease();

            scene()->removeItem(this);

            delete this;

            game->checkPlayerTank();

            return;
        }
    }

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
