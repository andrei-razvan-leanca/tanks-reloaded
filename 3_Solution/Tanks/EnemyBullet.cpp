#include "EnemyBullet.h"
#include "Game.h"

extern Game* game;

EnemyBullet::EnemyBullet(const int& rotation): iBullet{rotation}
{
    game->countBullets+=1;

    time=new QTimer();
    connect(time,SIGNAL(timeout()),this,SLOT(move()));
    time->start(50);
}

EnemyBullet::~EnemyBullet()
{
    game->countBullets-=1;
}

void EnemyBullet::move()
{
    //if bullet collides with player, destroy both
    QList<QGraphicsItem*> colliding_items=collidingItems();

    for(auto a:colliding_items){

        if(typeid(*(a))==typeid(LightTank) || typeid(*(a))==typeid(MediumTank) || typeid(*(a))==typeid(HeavyTank) || typeid(*(a))==typeid(SuperHeavyTank)|| typeid(*(a))==typeid(IndestructibleObject) || typeid(*(a))==typeid(Score) || typeid(*(a))==typeid(Health)){
            scene()->removeItem(this);

            delete this;

            return;
        }

        else if(typeid(*(a))==typeid(Base) || typeid(*(a))==typeid(NormalObject)){
            scene()->removeItem(a);
            scene()->removeItem(this);

            delete a;
            delete this;

            return;
        }

        else if(typeid(*(a))==typeid(PlayerTankFirst) || typeid(*(a))==typeid(PlayerTankSecond)){

            if(typeid(*(a))==typeid(PlayerTankFirst)){
                game->health->decrease();
            }

            else{
                game->health1->decrease();
            }

            scene()->removeItem(this);

            delete this;

            game->checkPlayerTank();

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
