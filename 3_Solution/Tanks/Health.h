#ifndef HEALTH_H
#define HEALTH_H

#include<QGraphicsTextItem>
#include<QFont>

class Health:public QGraphicsTextItem
{
private:
    int health;
public:
    Health();
    ~Health();

    void decrease();
    void resetHealth();
    int getHealth();
};

#endif // HEALTH_H
