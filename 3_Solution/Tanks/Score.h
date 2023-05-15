#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QFont>

class Score : public QGraphicsTextItem
{
private:
    int score;
public:
    Score();
    ~Score();

    void setScore(const int&);
    int getScore();
};

#endif // SCORE_H
