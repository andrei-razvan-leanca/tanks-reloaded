#ifndef HEAVYTANK_H
#define HEAVYTANK_H

#include "BotTank.h"

class HeavyTank : public BotTank
{
public:
    HeavyTank(const int&, const int&);
    ~HeavyTank();

    void setBulletPos(iBullet*)override;
};

#endif // HEAVYTANK_H
