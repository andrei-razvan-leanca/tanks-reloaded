#include "PlayerTankSecond.h"
#include "Game.h"

extern Game* game;

PlayerTankSecond::PlayerTankSecond(const int& w, const int& h):PlayerTank{w,h}
{
    setPos(width-boundingRect().width()*10, height - boundingRect().height());
}

PlayerTankSecond::~PlayerTankSecond()
{

}

void PlayerTankSecond::keyPressEvent(QKeyEvent *event)
{
    if((x()>=game->lObj->x() && (x() + boundingRect().width())<=(game->lObj->x() + game->lObj->boundingRect().width())) &&  (((y() + 80)>=game->lObj->y()) && ((y() + 30)<= game->lObj->y() + game->lObj->boundingRect().height()))){
        if(!checkBush){
            checkBush=true;
        }
    }

    //verificam daca se afla in al doilea tufis
    else if((x()>=game->rObj->x() && (x() + boundingRect().width()) <=(game->rObj->x() + game->rObj->boundingRect().width())) && ((y()+80) >=game->rObj->y() && (y() + 30) <=(game->rObj->y() + game->rObj->boundingRect().height()))){
        if(!checkBush){
            checkBush=true;
        }
    }

    else if(checkBush){
        checkBush=false;
    }

    if(event->key()==Qt::Key_P){
        game->checkPause();
    }

    if(!game->isOver && !game->isPaused){
        if(event->key()==Qt::Key_Up && y()>0){
            setPos(x(),y()-10);
            rotation=180;
            checkColliding("up");
        }

        else if(event->key()==Qt::Key_Down && y()+boundingRect().height()<height){
            setPos(x(),y()+10);
            rotation=0;
            checkColliding("down");
        }

        else if(event->key()==Qt::Key_Left && x()>30){
            setPos(x()-10,y());
            rotation=90;
            checkColliding("left");
        }

        else if(event->key()==Qt::Key_Right && x() + boundingRect().width()*2 <width){
            setPos(x()+10,y());
            rotation=270;
            checkColliding("right");
        }

        else {
            checker=true;
        }

        setRotation(rotation);

        if(event->key()==Qt::Key_K){
            iBullet* bullet=new PlayerBullet(rotation);
            bullet->recognizeTank();
            setBulletPos(bullet);
            bullets.push_back(bullet);
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
