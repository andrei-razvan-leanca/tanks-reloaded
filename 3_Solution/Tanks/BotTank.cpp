#include "BotTank.h"
#include "Game.h"

extern Game* game;

BotTank::BotTank(const int& w, const int& h):iTank{w,h}
{
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

void BotTank::checkColliding(QString direction)
{
    checker=false;
    QList<QGraphicsItem*> colliding_items=collidingItems();
    for(auto a:colliding_items){
        if(typeid(*(a))==typeid(LightTank) || typeid(*(a))==typeid(MediumTank) || typeid(*(a))==typeid(HeavyTank) || typeid(*(a))==typeid(SuperHeavyTank)|| typeid((*a))==typeid(PlayerTankFirst) || typeid(*(a))==typeid(PlayerTankSecond) || typeid(*(a))==typeid(Base) || typeid(*(a))==typeid(Score) || typeid(*(a))==typeid(Health) || typeid(*(a))==typeid(IndestructibleObject) || typeid(*(a))==typeid(NormalObject) ){

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

void BotTank::initializeBot()
{
    checker=true;

    center=boundingRect().center();
    origin=QPointF(center.x(), center.y());
    setTransformOriginPoint(origin);

    setPos(width/2,0);

    timeShots=new QTimer();
    connect(timeShots,SIGNAL(timeout()),this,SLOT(shotPlayer()));
    timeShots->start(1000);

    timeMove= new QTimer();
    connect(timeMove,SIGNAL(timeout()),this,SLOT(moveBotTank()));
    timeMove->start(50);
}
