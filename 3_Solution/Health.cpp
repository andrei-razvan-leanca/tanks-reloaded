#include "Health.h"

Health::Health()
{
    health=3;
    setPos(0,20);
    //draw the text
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

Health::~Health()
{

}

void Health::decrease()
{
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
}

void Health::resetHealth()
{
    health=3;
    setPlainText(QString("Health: ") + QString::number(health));
}

int Health::getHealth()
{
    return health;
}
