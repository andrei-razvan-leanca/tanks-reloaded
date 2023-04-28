#include "iTank.h"

iTank::iTank(const int &w, const int &h):width{w},height{h}
{
    rotation=0;
    verifyColliding=0;
}

iTank::~iTank()
{

}

int iTank::getWidth()
{
    return width;
}

int iTank::getHeight()
{
    return height;
}

int iTank::getHealth()
{
    return health;
}

int iTank::getRotatin()
{
    return rotation;
}

void iTank::increaseHealth()
{
    health++;
}

void iTank::decreaseHealth()
{
    health--;
}

void iTank::setHealth(const int &h)
{
    health=h;
}

void iTank::setRotate(const int &r)
{
    rotation=r;
}
