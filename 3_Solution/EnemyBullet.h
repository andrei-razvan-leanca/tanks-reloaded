#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include"iBullet.h"

class EnemyBullet : public iBullet
{
    Q_OBJECT
public:
    EnemyBullet(const int& rotation);
    ~EnemyBullet();
public slots:
    void move();
};

#endif // ENEMYBULLET_H
