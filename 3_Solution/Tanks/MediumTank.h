#ifndef MEDIUMTANK_H
#define MEDIUMTANK_H

#include "BotTank.h"

class MediumTank:public BotTank
{
public:
    MediumTank(const int&, const int&);
    ~MediumTank();

    void setBulletPos(iBullet*)override;
};

#endif // MEDIUMTANK_H
