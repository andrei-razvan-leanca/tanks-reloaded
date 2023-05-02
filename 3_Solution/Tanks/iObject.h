#ifndef IOBJECT_H
#define IOBJECT_H

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

class iObject: public QGraphicsPixmapItem, public QObject
{
protected:
    qreal xPos;
    qreal yPos;
public:
    iObject(const qreal x, const qreal y);
    ~iObject();
};

#endif // IOBJECT_H
