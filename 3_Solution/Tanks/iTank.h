#ifndef ITANK_H
#define ITANK_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include<QKeyEvent>
#include <QObject>
#include <QDebug>
#include <QList>
#include <QString>
#include <QTime>
#include <QApplication>
#include "iBullet.h"

class iTank: public QGraphicsPixmapItem, public QObject
{
protected:
    int width;
    int height;
    int health;
    int rotation;

    QPointF center;
    QPointF origin;

    std::vector<iBullet*> bullets;

    bool checker;
    bool checkBush=false;
    bool removeItem=false;
public:
    iTank(const int& w, const int& h);
    virtual ~iTank();

    int getWidth();
    int getHeight();
    int getHealth();
    int getRotatin();

    void increaseHealth();
    void decreaseHealth();
    void setHealth(const int& h);
    void setRotate(const int& r);
    void positionWhenColliding(QString);
    void moveTank(QKeyEvent*);

    virtual void checkColliding(QString)=0;
    virtual void setBulletPos(iBullet*)=0;
public slots:

};

#endif // ITANK_H
