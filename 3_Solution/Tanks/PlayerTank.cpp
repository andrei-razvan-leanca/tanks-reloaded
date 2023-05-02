#include "PlayerTank.h"
#include "Game.h"
#include "BotTank.h"
#include "Score.h"
#include "Health.h"
#include "Base.h"
#include "IndestructibleObject.h"
#include "NormalObject.h"

extern Game* game;

PlayerTank::PlayerTank(const int& w, const int& h):iTank{w,h}{
    health=3;

    setPixmap(QPixmap(":/images/playerTank.png"));
    center=boundingRect().center();
    origin=QPointF(center.x(), center.y());
    setTransformOriginPoint(origin);

    rotation=180;
    setRotation(rotation);

    setPos( boundingRect().width()*8 ,height-(int)boundingRect().height());

    bulletSound=new QMediaPlayer();
    bulletSound->setSource(QUrl("qrc:/sounds/gunshot"));
}

PlayerTank::~PlayerTank()
{

}

void PlayerTank::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_P){
        game->checkPause();
    }

    if(!game->isOver && !game->isPaused){
        moveTank(event);

        if(event->key()==Qt::Key_Space){
            iBullet* bullet=new PlayerBullet(rotation);

            setBulletPos(bullet);
            bullets.push_back(bullet);

            //play bulletSound
            if(bulletSound->PlayingState){
                bulletSound->setPosition(0);
            }
            else if(bulletSound->StoppedState){
                bulletSound->play();
            }
        }
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
        bullet->setPixmap(QPixmap(":/images/blank.png"));
    }
    scene()->addItem(bullet);
}

void PlayerTank::checkColliding(QString direction)
{
    QList<QGraphicsItem*> colliding_items=collidingItems();
    for(auto a:colliding_items){

        if(typeid(*(a))==typeid(BotTank) || typeid(*(a))==typeid(Base) || typeid(*(a))==typeid(IndestructibleObject) || typeid(*(a))==typeid(NormalObject) || typeid(*(a))==typeid(Score) || typeid(*(a))==typeid(Health)){

            positionWhenColliding(direction);

            return;
        }
    }
}

