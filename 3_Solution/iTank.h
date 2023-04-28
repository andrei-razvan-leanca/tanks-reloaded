#ifndef ITANK_H
#define ITANK_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include<QKeyEvent>
#include <QObject>
#include <QDebug>
#include <QList>
#include "stdlib.h"

class iTank: public QGraphicsPixmapItem, public QObject
{
protected:
    int width;
    int height;
    int health;
    int rotation;
    int verifyColliding;
    QPointF center;
    QPointF origin;
public:
    iTank(const int& w, const int &h);
    virtual ~iTank();

    int getWidth();
    int getHeight();
    int getHealth();
    int getRotatin();

    void increaseHealth();
    void decreaseHealth();
    void setHealth(const int& h);
    void setRotate(const int& r);

    virtual void checkColliding()=0;
};

#endif // ITANK_H
