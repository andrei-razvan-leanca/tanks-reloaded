#ifndef IBULLET_H
#define IBULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QList>
#include <QObject>
#include <QTimer>

class iBullet:public QGraphicsPixmapItem, public QObject
{
    //Q_OBJECT
protected:
    int widthBullet;
    int heightBullet;
    int r;
    int left;
    int right;
    int up;
    int down;
    QPointF center;
    QPointF origin;
public:
    iBullet(const int& rotation);
    virtual ~iBullet();

    void setDirection(const int& rotation);
};

#endif // IBULLET_H
