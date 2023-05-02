#ifndef BOTTANK_H
#define BOTTANK_H

#include "iTank.h"
#include "EnemyBullet.h"

class BotTank :public iTank
{
    Q_OBJECT
protected:
    QKeyEvent* event=nullptr;
    QTimer* timeShots;
    QTimer* timeMove;

    friend class Game;
public:

    BotTank(const int& w, const int& h);
    ~BotTank();

    void setBulletPos(iBullet*)override;
    int setLocation();
    void checkColliding(QString)override;
    void setEvent();
public slots:
    void shotPlayer();
    void moveBotTank();
};

#endif // BOTTANK_H
