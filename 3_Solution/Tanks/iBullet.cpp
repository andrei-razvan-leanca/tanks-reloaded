#include "iBullet.h"
#include "Game.h"

extern Game *game;

iBullet::iBullet(const int& rotation)
{
    setPixmap(QPixmap(":/images/bullet.png"));
    setDirection(rotation);

    center=boundingRect().center();
    origin=QPointF(center.x(), center.y());
    setTransformOriginPoint(center);

    bulletSpeed=20;
}

iBullet::~iBullet()
{
    game->countBullets-=1;
}

void iBullet::setDirection(const int& rotation)
{
    setRotation(rotation);

    if(rotation==0){
        left=false;
        right=false;
        up=false;
        down=true;
    }

    else if(rotation==180){
        left=false;
        right=false;
        up=true;
        down=false;
    }

    else if(rotation==270){
        left=false;
        right=true;
        up=false;
        down=false;
    }

    else{
        left=true;
        right=false;
        up=false;
        down=false;
    }
}

void iBullet::moveBullet()
{
    //verificam daca se afla in primul tufis
    if((x()>=game->lObj->x() && (x() + boundingRect().width())<=(game->lObj->x() + game->lObj->boundingRect().width())) && (y()>=game->lObj->y() && (y() + boundingRect().height() <= game->lObj->y() + game->lObj->boundingRect().height()))){
        if(!checkBush){
            checkBush=true;
        }
    }

    //verificam daca se afla in al doilea tufis
    else if((x()>=game->rObj->x() && (x() + boundingRect().width()) <=(game->rObj->x() + game->rObj->boundingRect().width())) && (y()>=game->rObj->y() && (y() + boundingRect().height()) <=(game->rObj->y() + game->rObj->boundingRect().height()))){
        if(!checkBush){
            checkBush=true;
        }
    }

    else if(checkBush){
        checkBush=false;
    }

    if(up){
        setPos(x(),y()-bulletSpeed);
        if(y() <0){
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    else if(down){
        setPos(x(), y()+bulletSpeed);
        if(y() > game->playerTank->getHeight()){
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    else if(right){
        setPos(x()+bulletSpeed, y());
        if(x() > game->playerTank->getWidth()){
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    else {
        setPos(x()-bulletSpeed, y());
        if(x() < 0){
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
}

void iBullet::recognizeTank()
{
    recTank=true;
}
