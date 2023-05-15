#include "iTank.h"
#include "Game.h"

extern Game * game;

iTank::iTank(const int& w, const int& h):width{w}, height{h}
{
    rotation=0;
}

iTank::~iTank()
{

}

int iTank::getWidth()
{
    return width;
}

int iTank::getHeight()
{
    return height;
}

int iTank::getHealth()
{
    return health;
}

int iTank::getRotatin()
{
    return rotation;
}

void iTank::increaseHealth()
{
    health++;
}

void iTank::decreaseHealth()
{
    health--;
}

void iTank::setHealth(const int &h)
{
    health=h;
}

void iTank::setRotate(const int &r)
{
    rotation=r;
}

int iTank::setLocation()
{
    QList<QGraphicsItem*> colliding_items=collidingItems();

    for(auto a:colliding_items){
        if(typeid(*(a))==typeid(LightTank) || typeid(*(a))==typeid(MediumTank) || typeid(*(a))==typeid(HeavyTank) || typeid(*(a))==typeid(SuperHeavyTank) || typeid((*a))==typeid(PlayerTankFirst) || typeid((*a))==typeid(PlayerTankSecond) || typeid(*(a))==typeid(Score) || typeid(*(a))==typeid(Health) || typeid(*(a))==typeid(IndestructibleObject) || typeid(*(a))==typeid(NormalObject) || typeid(*(a))==typeid(Base)){
        return 1;
        }
    }

    return 0;
}

void iTank::positionWhenColliding(QString direction)
{
    if(direction=="up"){
        setPos(x(),y()+10);
    }

    else if(direction=="down"){
        setPos(x(),y()-10);
    }

    else if(direction=="left"){
        setPos(x()+10,y());
    }

    else {
        setPos(x()-10,y());
    }
}

void iTank::moveTank(QKeyEvent* event)
{
    checker=false;

    //verificam daca se afla in primul tufis
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

    if(true){

        if(event->key()==Qt::Key_W && y()>0){
            setPos(x(),y()-10);
            rotation=180;
            checkColliding("up");
        }

        else if(event->key()==Qt::Key_S && y()+boundingRect().height()<height){
            setPos(x(),y()+10);
            rotation=0;
            checkColliding("down");
        }

        else if(event->key()==Qt::Key_A && x()>30){
            setPos(x()-10,y());
            rotation=90;
            checkColliding("left");
        }

        else if(event->key()==Qt::Key_D && x() + boundingRect().width()*2 <width){
            setPos(x()+10,y());
            rotation=270;
            checkColliding("right");
        }

        else {
            checker=true;
        }

    }

    setRotation(rotation);
}
