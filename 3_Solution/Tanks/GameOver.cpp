#include "GameOver.h"

GameOver::GameOver()
{
    setPos(600, 250);

    setPlainText(QString("GAME OVER"));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",36));
}

GameOver::~GameOver()
{

}
