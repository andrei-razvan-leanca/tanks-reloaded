#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include<QMediaPlayer>
#include <stack>
#include "PlayerTank.h"
#include "BotTank.h"
#include "Score.h"
#include "Health.h"
#include "Base.h"
#include "GamePaused.h"
#include "CamouflageObject.h"
#include "IndestructibleObject.h"
#include "NormalObject.h"

class Game: public QGraphicsView
{
    Q_OBJECT
private:
    int width=1400;
    int height=700;
    static Game* instance;

    Game();
    ~Game();
public:
    static Game* getInstance();
    static void destroyInstance();

    QGraphicsScene* scene;
    PlayerTank* playerTank;
    std::vector<BotTank*> botTanks;
    Score* score;
    Health* health;
    Base* base;

    int countBullets=0;
    bool isOver=false;
    bool isPaused=false;

    QTimer* timeOver;
    GamePaused* gamePaused;

    CamouflageObject* lObj;
    CamouflageObject* rObj;

    void initializeMap();

    void createBotTanks();
    void addBotTank();
    void createPlayerTank();
    void checkPlayerTank();
    void createBase();
    void conditionToCreateBots(BotTank* tank);
    void checkPlayerBullets();
    void checkBotBullets();

    void checkGameOver();
    void pauseGame();
    void resumeGame();
    void checkPause();

    void createObjects();
    void createCamouflageObject();
    void createIndestructibleObject();
    void createNormalObject();

    void runSinglePlayer();

public slots:
    void exitGame();
};

#endif // GAME_H
