#include "PlayerTankFirst.h"
#include "Game.h"

extern Game* game;

PlayerTankFirst::PlayerTankFirst(const int& w, const int& h):PlayerTank{w,h}
{
    rotation=180;
    setRotation(rotation);
    setPos(boundingRect().width()*8, height-(int)boundingRect().height());
}

PlayerTankFirst::~PlayerTankFirst()
{

}

void PlayerTankFirst::keyPressEvent(QKeyEvent *event)
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
