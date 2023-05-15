#include "PlayerBullet.h"
#include "Game.h"

extern Game* game;

PlayerBullet::PlayerBullet(const int& rotation): iBullet{rotation}
{
    game->countBullets+=1;

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

        if( typeid(*(a))==typeid(PlayerTankSecond) || typeid(*(a))==typeid(PlayerTankFirst) || typeid(*(a))==typeid(IndestructibleObject) || typeid(*(a))==typeid(Score) || typeid(*(a))==typeid(Health)){

            if(game->mode==3){
                if(typeid(*(a))==typeid(PlayerTankFirst)){
                    game->health->decrease();
                    game->checkPlayerTank1v1();
                }

                else if(typeid(*(a))==typeid(PlayerTankSecond)){
                    game->health1->decrease();
                    game->checkPlayerTank1v1();
                }
            }

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

        else if(typeid(*(a))==typeid(LightTank) || typeid(*(a))==typeid(MediumTank) || typeid(*(a))==typeid(HeavyTank) || typeid(*(a))==typeid(SuperHeavyTank)){
            bool destroyBot=false;

            if(typeid(*(a))==typeid(LightTank)){
                LightTank* lightTank=dynamic_cast<LightTank*>(a);
                lightTank->health-=1;
                game->checkLightTank=true;
                if(lightTank->health==0){destroyBot=true;}
            }
            else if(typeid(*(a))==typeid(MediumTank)){
                MediumTank* mediumTank=dynamic_cast<MediumTank*>(a);
                mediumTank->health-=1;
                game->checkMediumTank=true;
                if(mediumTank->health==0){destroyBot=true;}
            }
            else if(typeid(*(a))==typeid(HeavyTank)){
                HeavyTank* heavyTank=dynamic_cast<HeavyTank*>(a);
                heavyTank->health-=1;
                game->checkHeavyTank=true;
                if(heavyTank->health==0){destroyBot=true;}
            }
            else if(typeid(*(a))==typeid(SuperHeavyTank)){
                SuperHeavyTank* superHeavyTank=dynamic_cast<SuperHeavyTank*>(a);
                superHeavyTank->health-=1;
                game->checkSuperHeavyTank=true;
                if(superHeavyTank->health==0){destroyBot=true;}
            }

            if(destroyBot){

                if(!recTank){
                    int s=game->setScore();
                    game->score->setScore(game->score->getScore() + s);
                }
                else{
                    int s=game->setScore();
                    game->score1->setScore(game->score1->getScore() + s);
                }

                scene()->removeItem(a);
                delete a;
                game->addBotTank();
            }

            scene()->removeItem(this);
            delete this;

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
