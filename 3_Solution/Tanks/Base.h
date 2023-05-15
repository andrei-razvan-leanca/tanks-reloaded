#ifndef BASE_H
#define BASE_H


#include <QGraphicsPixmapItem>
#include <QDebug>
#include "GameOver.h"

class Base: public QGraphicsPixmapItem
{
public:
    Base(const int& , const int& );
    ~Base();
};

#endif // BASE_H
