#ifndef PLAYERTANK_H
#define PLAYERTANK_H

#include<QMediaPlayer>
#include <QTimer>
#include <QElapsedTimer>
#include"PlayerBullet.h"
#include "iTank.h"

class PlayerTank :public iTank
{
protected:
    QMediaPlayer* bulletSound;
    friend class Game;
public:
    PlayerTank(const int& , const int& );
    virtual ~PlayerTank();

    void setBulletPos(iBullet*)override;
    void checkColliding(QString)override;

    virtual void keyPressEvent(QKeyEvent*)=0;
};

#endif // PLAYERTANK_H
