#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include<vector>
#include<QMediaPlayer>
#include "PlayerTank.h"
#include "BotTank.h"
#include "Score.h"
#include "Health.h"

class Game: public QGraphicsView
{
private:
    int width=1400;
    int height=700;
public:
    Game();
    ~Game();

    QGraphicsScene* scene;
    PlayerTank* playerTank;
    std::vector<BotTank*> botTanks;
    BotTank* botTank;
    Score* score;
    Health* health;

    void createBotTanks();
    void addBotTank();

    void createPlayerTank();
    void checkPlayerTank();
};

#endif // GAME_H
