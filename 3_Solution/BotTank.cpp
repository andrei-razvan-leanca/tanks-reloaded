#include "BotTank.h"

BotTank::BotTank(const int& w, const int& h):iTank{w,h}{
    int randomX=rand()%(width);
    int randomY=rand()%(height/2);

    setPixmap(QPixmap(":/images/botTank.png"));
    center=boundingRect().center();
    origin=QPointF(center.x(), center.y());
    setTransformOriginPoint(origin);
    setPos(randomX,randomY);

    //qDebug()<<"widthTank: "<<boundingRect().width()<<"heightTank: "<< boundingRect().height();

    QTimer* time=new QTimer();
    connect(time,SIGNAL(timeout()),this,SLOT(shotPlayer()));

    time->start(500);
}

BotTank::~BotTank()
{

}

void BotTank::shotPlayer()
{
    EnemyBullet* bullet=new EnemyBullet(0);
    bullet->setPos(x() + 24,y() + 100);
    scene()->addItem(bullet);
}

void BotTank::checkColliding()
{

}
