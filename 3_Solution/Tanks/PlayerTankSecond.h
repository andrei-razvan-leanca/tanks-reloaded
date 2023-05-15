#ifndef PLAYERTANKSECOND_H
#define PLAYERTANKSECOND_H

#include "PlayerTank.h"

class PlayerTankSecond : public PlayerTank
{
public:
    PlayerTankSecond(const int& w, const int& h);
    ~PlayerTankSecond();

    virtual void keyPressEvent(QKeyEvent* event)override;
};

#endif // PLAYERTANKSECOND_H
