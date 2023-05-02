#include "GamePaused.h"

GamePaused::GamePaused()
{
    setPos(600, 250);

    setPlainText(QString("PAUSE"));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",36));
}

GamePaused::~GamePaused()
{

}
