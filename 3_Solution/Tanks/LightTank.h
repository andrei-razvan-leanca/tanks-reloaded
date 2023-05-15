#ifndef LIGHTTANK_H
#define LIGHTTANK_H

#include "BotTank.h"

class LightTank : public BotTank
{
public:
    LightTank(const int&, const int&);
    ~LightTank();

    void setBulletPos(iBullet*)override;
};

#endif // LIGHTTANK_H
