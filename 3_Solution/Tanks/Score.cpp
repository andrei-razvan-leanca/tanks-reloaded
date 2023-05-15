#include "Score.h"

Score::Score()
{
    score=0;
    setPos(0,0);
    //draw the text
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

Score::~Score()
{

}

void Score::setScore(const int& s)
{
    score=s;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore()
{
    return score;
}
