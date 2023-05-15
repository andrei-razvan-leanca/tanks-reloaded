#ifndef IBULLET_H
#define IBULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QList>
#include <QObject>
#include <QTimer>
#include <vector>

class iBullet:public QGraphicsPixmapItem, public QObject
{
protected:
    int bulletSpeed;

    bool left;
    bool right;
    bool up;
    bool down;
    bool checkBush=false;
    bool removeItem=false;
    bool recTank=false;

    QPointF center;
    QPointF origin;

    QTimer* time;

    friend class Game;
    friend class BotTank;
    friend class PlayerTank;
public:
    iBullet(const int&);
    virtual ~iBullet();

    void setDirection(const int&);
    void moveBullet();
    void recognizeTank();
};

#endif // IBULLET_H
