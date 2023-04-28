#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H

#include"iBullet.h"

class PlayerBullet : public iBullet
{
    Q_OBJECT
public:
    PlayerBullet(const int& rotation);
    ~PlayerBullet();
public slots:
    void move();
};

#endif // PLAYERBULLET_H
