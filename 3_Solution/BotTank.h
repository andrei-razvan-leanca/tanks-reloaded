#ifndef BOTTANK_H
#define BOTTANK_H

#include "iTank.h"
#include "EnemyBullet.h"

class BotTank :public iTank
{
    Q_OBJECT
public:
    BotTank(const int& w,const int& h);
    ~BotTank();

public slots:
    void shotPlayer();

    void checkColliding();
};

#endif // BOTTANK_H
