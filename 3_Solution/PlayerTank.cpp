#include "PlayerTank.h"
#include "Game.h"
#include "BotTank.h"

extern Game* game;

PlayerTank::PlayerTank(const int& w, const int& h):iTank{w,h}{
    health=3;
    setPixmap(QPixmap(":/images/playerTank.png"));
    center=boundingRect().center();
    origin=QPointF(center.x(), center.y());
    setTransformOriginPoint(origin);
    rotation=180;
    setRotation(rotation);


    //qDebug()<<"widthTank: "<<boundingRect().width()<<"heightTank: "<< boundingRect().height();

    setPos(width/2,height-boundingRect().height());

    bulletSound=new QMediaPlayer();
    bulletSound->setSource(QUrl("qrc:/sounds/gunshot"));
}

PlayerTank::~PlayerTank()
{

}


void PlayerTank::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<"pos: "<<x()<<"  "<< y();



    if(event->key()==Qt::Key_W && y()>0 && verifyColliding==0){
        setPos(x(),y()-10);
        rotation=180;
    }

    else if(event->key()==Qt::Key_S && y()+boundingRect().height()<height && verifyColliding==0){
        setPos(x(),y()+10);
        rotation=0;
    }

    else if(event->key()==Qt::Key_A && x()>0 && verifyColliding==0){
        setPos(x()-10,y());
        rotation=90;
    }

    else if(event->key()==Qt::Key_D && x() + boundingRect().width()*2 <width && verifyColliding==0){
        setPos(x()+10,y());
        rotation=270;
    }

    else if(event->key()==Qt::Key_Space){
        bullet=new PlayerBullet(rotation);

        setBulletPos();

        //play bulletSound
        if(bulletSound->PlayingState){
            bulletSound->setPosition(0);
        }
        else if(bulletSound->StoppedState){
            bulletSound->play();
        }
    }

    checkColliding();
    verifyColliding=0;
    setRotation(rotation);
}

void PlayerTank::setBulletPos()
{
    if(rotation==0){
        bullet->setPos(x() + 22, y() + 120);
    }

    else if(rotation==180){
        bullet->setPos(x() + 24, y() - 10);
    }

    else if(rotation==270){
        bullet->setPos(x() + 90, y() + 58);
    }

    else{
        bullet->setPos(x() - 50 , y() + 58);
    }
    scene()->addItem(bullet);
}

void PlayerTank::checkColliding()
{
    QList<QGraphicsItem*> colliding_items=collidingItems();
    for(auto a:colliding_items){
        if(typeid(*(a))==typeid(BotTank)){
            verifyColliding=1;
            return;
        }
    }
}

