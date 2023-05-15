#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include<QMediaPlayer>
#include <stack>
#include "Score.h"
#include "Health.h"
#include "Base.h"
#include "GamePaused.h"
#include "CamouflageObject.h"
#include "IndestructibleObject.h"
#include "NormalObject.h"
#include "PlayerTankFirst.h"
#include "PlayerTankSecond.h"
#include "FactoryBotTanks.h"

class Game: public QGraphicsView
{
    Q_OBJECT
private:
    int width=1400;
    int height=700;
    static Game* instance;

    Game(const int&, const int&);
    ~Game();
public:
    static Game* getInstance(const int&, const int&);
    static void destroyInstance();

    QGraphicsScene* scene;
    PlayerTank* playerTank;
    PlayerTank* playerTank1;
    std::vector<BotTank*> botTanks;
    Score* score;
    Health* health;
    Score* score1;
    Health* health1;
    Base* base;

    int countBullets=0;
    int mode;
    int level;
    int lightTanks;
    int mediumTanks;
    int heavyTanks;
    int superHeavyTanks;
    bool checkLightTank=false;
    bool checkMediumTank=false;
    bool checkHeavyTank=false;
    bool checkSuperHeavyTank=false;
    bool isOver=false;
    bool isPaused=false;

    QTimer* timeOver;
    GamePaused* gamePaused;

    CamouflageObject* lObj;
    CamouflageObject* rObj;
    NormalObject* nml1;
    QGraphicsPixmapItem* focusedItem;

    void createPlayerTank();
    void createPlayersTank();
    void checkPlayerTank();
    void checkPlayerTank1v1();

    void conditionToCreateBots(iTank* tank);
    void createBotTanks();
    void addBotTank();

    void checkPlayerBullets();
    void checkBotBullets();

    void checkGameOver();
    void pauseGame();
    void resumeGame();
    void checkPause();

    void initializeMap();
    void createBase();
    void createObjects();
    void createCamouflageObject();
    void createIndestructibleObject();
    void createNormalObject();

    void keyPressEvent(QKeyEvent*)override;
    void chooseModeAndLevel();
    int setScore();

    void runSinglePlayer();
    void runSinglePlayerCoOp();
    void runSinglePlayer1v1();
public slots:
    void exitGame();
};

#endif // GAME_H
