#ifndef PLAYERTANK_H
#define PLAYERTANK_H

#include<QMediaPlayer>
#include"PlayerBullet.h"
#include "iTank.h"

class PlayerTank :public iTank
{
private:
    QMediaPlayer* bulletSound;
    PlayerBullet* bullet;
    static PlayerTank* instance;

    PlayerTank(const int& w,const int& h);
    ~PlayerTank();
public:
    static PlayerTank* getInstance(const int& w,const int& h);
    static void destroyInstance();

    void keyPressEvent(QKeyEvent* event);
    void setBulletPos();

    void checkColliding();

};

#endif // PLAYERTANK_H
