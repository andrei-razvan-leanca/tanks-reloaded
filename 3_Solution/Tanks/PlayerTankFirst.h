#ifndef PLAYERTANKFIRST_H
#define PLAYERTANKFIRST_H

#include "PlayerTank.h"

class PlayerTankFirst : public PlayerTank
{
public:
    PlayerTankFirst(const int& w, const int& h);
    ~PlayerTankFirst();

    virtual void keyPressEvent(QKeyEvent* event) override;
};

#endif // PLAYERTANKFIRST_H
