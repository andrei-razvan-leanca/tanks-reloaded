#ifndef SUPERHEAVYTANK_H
#define SUPERHEAVYTANK_H

#include "BotTank.h"

class SuperHeavyTank : public BotTank
{
public:
    SuperHeavyTank(const int&, const int&);
    ~SuperHeavyTank();

    void setBulletPos(iBullet*)override;
};

#endif // SUPERHEAVYTANK_H
