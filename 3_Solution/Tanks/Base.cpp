#include "Base.h"
#include "Game.h"

extern Game* game;

Base::Base(const int& width, const int& height)
{
    setPixmap(QPixmap(":/images/drapel.jpg"));
    setPos(width/2 - 50,height - (int)boundingRect().height());
}

Base::~Base()
{
    game->isOver=true;
    game->checkGameOver();
}
