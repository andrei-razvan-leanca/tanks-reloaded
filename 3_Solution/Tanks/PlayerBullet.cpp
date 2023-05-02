#include "PlayerBullet.h"
#include "BotTank.h"
#include "Game.h"
#include "Health.h"
#include "Score.h"
#include "NormalObject.h"
#include "IndestructibleObject.h"

extern Game* game;

PlayerBullet::PlayerBullet(const int& rotation): iBullet{rotation}
{
    game->countBullets+=1;
    qDebug()<<"Bullets : "<< game->countBullets;

    time=new QTimer();
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

        if(typeid(*(a))==typeid(PlayerTank) || typeid(*(a))==typeid(IndestructibleObject) || typeid(*(a))==typeid(Score) || typeid(*(a))==typeid(Health)){
            scene()->removeItem(this);
            delete this;

            return;
        }

        else if(typeid(*(a))==typeid(NormalObject) || typeid(*(a))==typeid(Base)){
           scene()->removeItem(a);
           scene()->removeItem(this);

           delete a;
           delete this;

           return;
        }

        else if(typeid(*(a))==typeid(BotTank)){
            game->score->increase();

            scene()->removeItem(a);
            scene()->removeItem(this);

            delete a;
            delete this;

            game->addBotTank();

            return;
        }
    }

    if(!game->isOver && !game->isPaused){
        moveBullet();
    }

    if(checkBush && !removeItem){
        setOpacity(0);
        removeItem=true;
    }

    else if(!checkBush && removeItem){
        setOpacity(1);
        removeItem=false;
    }
}
