#ifndef PLAYERTANK_H
#define PLAYERTANK_H

#include<QMediaPlayer>
#include <QTimer>
#include <QElapsedTimer>
#include"PlayerBullet.h"
#include "iTank.h"

class PlayerTank :public iTank
{
private:
    QMediaPlayer* bulletSound;
    friend class Game;
public:
    PlayerTank(const int& w, const int& h);
    ~PlayerTank();

    void keyPressEvent(QKeyEvent* event);
    void setBulletPos(iBullet*)override;
    void checkColliding(QString)override;
};

#endif // PLAYERTANK_H
