#ifndef FACTORYBOTTANKS_H
#define FACTORYBOTTANKS_H

#include "LightTank.h"
#include "MediumTank.h"
#include "HeavyTank.h"
#include "SuperHeavyTank.h"

class FactoryBotTanks
{
public:
    FactoryBotTanks();

    static BotTank* getLightTank(const int& w, const int& h){
        return new LightTank(w,h);
    }

    static BotTank* getMediumTank(const int& w, const int& h){
        return new MediumTank(w,h);
    }

    static BotTank* getHeavyTank(const int& w, const int& h){
        return new HeavyTank(w,h);
    }

    static BotTank* getSuperHeavyTank(const int& w, const int& h){
        return new SuperHeavyTank(w,h);
    }
};

#endif // FACTORYBOTTANKS_H
