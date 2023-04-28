#include "Game.h"
#include<QBrush>
#include<QImage>

Game::Game()
{
    //create a scene
    scene= new QGraphicsScene();
    scene->setSceneRect(0,0,width,height);
    setBackgroundBrush(QBrush(QImage(":/images/background.png")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(width,height);

    createPlayerTank();
    createBotTanks();

    //activate playerTank
    playerTank->setFlag(QGraphicsItem::ItemIsFocusable);
    playerTank->setFocus();

    //create the score and the health
    score=new Score();
    scene->addItem(score);

    health=new Health();
    scene->addItem(health);

    //play background music
    QMediaPlayer * music = new QMediaPlayer();
    music->setSource(QUrl("qrc:/sounds/destroyed.mp3"));
    music->play();

    show();
}

Game::~Game()
{

}

void Game::addBotTank()
{
    std::vector<BotTank*>::iterator itr;
    for(itr=botTanks.begin();itr!=botTanks.end();itr++){
        if((*itr)==nullptr){
            botTanks.erase(itr);
        }
    }

    BotTank* botTank=new BotTank(width,height);
    scene->addItem(botTank);
    botTanks.push_back(botTank);
}

void Game::createPlayerTank()
{
    playerTank= new PlayerTank(width,height);
    scene->addItem(playerTank);
}

void Game::checkPlayerTank()
{
    if(health->getHealth()==0){
        playerTank->setPos(width/2,height-100);
        playerTank->setRotation(180);
        health->resetHealth();
    }
}

void Game::createBotTanks()
{
    //for(int i=0;i<4;i++){
        //botTanks.push_back(new BotTank(width,height));
        //scene->addItem(botTanks.at(i));
    //}

    botTank= new BotTank(width,height);
    scene->addItem(botTank);
}

