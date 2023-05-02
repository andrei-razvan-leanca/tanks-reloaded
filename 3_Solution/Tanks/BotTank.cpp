#include "BotTank.h"
#include "PlayerTank.h"
#include "Base.h"
#include "Game.h"
#include "Score.h"
#include "Health.h"
#include "IndestructibleObject.h"
#include "NormalObject.h"

extern Game* game;

BotTank::BotTank(const int& w, const int& h):iTank{w,h}{
    checker=true;
    setPixmap(QPixmap(":/images/botTank.png"));
    center=boundingRect().center();
    origin=QPointF(center.x(), center.y());
    setTransformOriginPoint(origin);

    int randomX=rand()%(width-(int)boundingRect().width());
    int randomY=rand()%(height/2);
    setPos(randomX,randomY);

    timeShots=new QTimer();
    connect(timeShots,SIGNAL(timeout()),this,SLOT(shotPlayer()));
    timeShots->start(1000);

    timeMove= new QTimer();
    connect(timeMove,SIGNAL(timeout()),this,SLOT(moveBotTank()));
    timeMove->start(50);
}

BotTank::~BotTank()
{

}

void BotTank::moveBotTank()
{
    if(!game->isOver && !game->isPaused){
        if(checker){
            if(event){
                delete event;
                event=nullptr;
            }
            setEvent();
        }
        moveTank(event);
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

void BotTank::shotPlayer()
{
    if(game->countBullets<500 && !game->isOver && !game->isPaused){
        iBullet* bullet=new EnemyBullet(rotation);
        setBulletPos(bullet);
        bullets.push_back(bullet);
    }
}

void BotTank::setBulletPos(iBullet* bullet)
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
        bullet->setPixmap(QPixmap(":/images/blank.png"));
    }

    scene()->addItem(bullet);
}

int BotTank::setLocation()
{
        QList<QGraphicsItem*> colliding_items=collidingItems();

        for(auto a:colliding_items){
            if(typeid(*(a))==typeid(BotTank) || typeid((*a))==typeid(PlayerTank) || typeid(*(a))==typeid(Score) || typeid(*(a))==typeid(Health) || typeid(*(a))==typeid(IndestructibleObject) || typeid(*(a))==typeid(NormalObject)){
                return 1;
            }
        }
        return 0;
}

void BotTank::checkColliding(QString direction)
{
    checker=false;
    QList<QGraphicsItem*> colliding_items=collidingItems();
    for(auto a:colliding_items){
        if(typeid(*(a))==typeid(BotTank) || typeid((*a))==typeid(PlayerTank) || typeid(*(a))==typeid(Base) || typeid(*(a))==typeid(Score) || typeid(*(a))==typeid(Health) || typeid(*(a))==typeid(IndestructibleObject) || typeid(*(a))==typeid(NormalObject) ){

            checker=true;
            positionWhenColliding(direction);

            return;
        }
    }
}

void BotTank::setEvent()
{
    int number=rand()%4;

    switch(number){
    case 0:
        event=new QKeyEvent(QEvent::KeyPress, Qt::Key_W, Qt::NoModifier);
        break;

    case 1:
        event=new QKeyEvent(QEvent::KeyPress, Qt::Key_S, Qt::NoModifier);
        break;

    case 2:
        event=new QKeyEvent(QEvent::KeyPress, Qt::Key_A, Qt::NoModifier);
        break;
    case 3:
        event=new QKeyEvent(QEvent::KeyPress, Qt::Key_D, Qt::NoModifier);
        break;

    default:
        break;
    }
}
