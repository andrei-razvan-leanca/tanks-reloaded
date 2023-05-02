#include "Game.h"
#include<QBrush>
#include<QImage>

Game* Game::instance=nullptr;

Game::Game()
{
    initializeMap();
    runSinglePlayer();
}

Game::~Game()
{

}

Game *Game::getInstance()
{
    if(!instance){
        instance=new Game();
    }
    return instance;
}

void Game::destroyInstance()
{
    if(instance){
        delete instance;
        instance=nullptr;
    }
}

void Game::initializeMap()
{
    //create a scene
    scene= new QGraphicsScene();
    scene->setSceneRect(0,0,width,height);
    setBackgroundBrush(QBrush(QImage(":/images/background.png")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(width,height);

    //create the score and the health
    score=new Score();
    scene->addItem(score);

    health=new Health();
    scene->addItem(health);
}

void Game::runSinglePlayer()
{
    //create the tanks, base and objects
    createBase();
    createObjects();
    createPlayerTank();
    createBotTanks();

    //activate playerTank
    playerTank->setFlag(QGraphicsItem::ItemIsFocusable);
    playerTank->setFocus();

    //play background music
    QMediaPlayer * music = new QMediaPlayer();
    music->setSource(QUrl("qrc:/sounds/destroyed.mp3"));
    music->play();

    show();
}

void Game::addBotTank()
{
    std::vector<BotTank*>::iterator itr;
    for(itr=botTanks.begin();itr!=botTanks.end();itr++){
        if((*itr)==nullptr){
            botTanks.erase(itr);
        }
    }

    botTanks.push_back(new BotTank(width,height));
    conditionToCreateBots(botTanks.at(botTanks.size()-1));
}

void Game::createPlayerTank()
{
    playerTank=new PlayerTank(width,height);
    scene->addItem(playerTank);
}

void Game::checkPlayerTank()
{
    if(health->getHealth()==0){
        playerTank->setPos(playerTank->boundingRect().width()*8,height-playerTank->boundingRect().height());
        playerTank->setRotation(180);
        health->resetHealth();
    }
}

void Game::createBase()
{
    base=new Base(width,height);
    scene->addItem(base);
}

void Game::conditionToCreateBots(BotTank* tank)
{
    scene->addItem(tank);
    if(tank->setLocation()){
        while(tank->setLocation()){
            int randomX=rand()%(width-(int)tank->boundingRect().width());
            int randomY=rand()%(height/2);
            tank->setPos(randomX,randomY);
        }
    }
}

void Game::checkGameOver()
{
    if(isOver){

//        for(auto a:botTanks){
//            a->timeMove->stop();
//            a->timeShots->stop();
//        }

        GameOver* gameOver=new GameOver();
        scene->addItem(gameOver);

        timeOver=new QTimer();
        connect(timeOver,SIGNAL(timeout()),this,SLOT(exitGame()));
        timeOver->start(3000);
    }
}

void Game::pauseGame()
{
    gamePaused=new GamePaused();
    scene->addItem(gamePaused);

    for(auto a:botTanks){
        a->timeMove->stop();
        a->timeShots->stop();
    }
}

void Game::resumeGame()
{
    scene->removeItem(gamePaused);
    delete gamePaused;
    gamePaused=nullptr;

    for(auto a:botTanks){
        a->timeMove->start();
        a->timeShots->start();
    }
}

void Game::exitGame()
{
    QApplication::exit();
}

void Game::checkPause()
{
    isPaused=!isPaused;

    if(isPaused){
        pauseGame();
    }

    else {
        resumeGame();
    }
}

void Game::createObjects()
{
    createCamouflageObject();
    createIndestructibleObject();
    createNormalObject();
}

void Game::createCamouflageObject()
{
    lObj=new CamouflageObject(0,200);
    scene->addItem(lObj);

    rObj=new CamouflageObject(width - lObj->boundingRect().width(),200);
    scene->addItem(rObj);
}

void Game::createIndestructibleObject()
{
    IndestructibleObject* ind1=new IndestructibleObject(300,200);
    scene->addItem(ind1);

    IndestructibleObject* ind2=new IndestructibleObject(1050,200);
    scene->addItem(ind2);

    IndestructibleObject* ind3=new IndestructibleObject(300,450);
    scene->addItem(ind3);

    IndestructibleObject* ind4=new IndestructibleObject(1050,450);
    scene->addItem(ind4);


    std::vector<IndestructibleObject*> indObjs;
    indObjs.push_back(new IndestructibleObject(600,250));
    scene->addItem(indObjs.at(0));
    for(int i=1;i<4;i++){
        indObjs.push_back(new IndestructibleObject(indObjs.at(i-1)->x()+ indObjs.at(0)->boundingRect().width(),indObjs.at(0)->y()));
        scene->addItem(indObjs.at(i));
    }

    indObjs.push_back(new IndestructibleObject(indObjs.at(0)->x(),indObjs.at(0)->y() + indObjs.at(0)->boundingRect().height()));
    scene->addItem(indObjs.at(4));
    for(int i=5;i<8;i++){
        indObjs.push_back(new IndestructibleObject(indObjs.at(i-1)->x()+ indObjs.at(0)->boundingRect().width(),indObjs.at(4)->y()));
        scene->addItem(indObjs.at(i));
    }

    indObjs.push_back(new IndestructibleObject(indObjs.at(0)->x(),indObjs.at(4)->y() + indObjs.at(4)->boundingRect().height()));
    scene->addItem(indObjs.at(8));
    for(int i=9;i<12;i++){
        indObjs.push_back(new IndestructibleObject(indObjs.at(i-1)->x()+ indObjs.at(0)->boundingRect().width(),indObjs.at(8)->y()));
        scene->addItem(indObjs.at(i));
    }

    indObjs.push_back(new IndestructibleObject(indObjs.at(0)->x(),indObjs.at(8)->y() + indObjs.at(8)->boundingRect().height()));
    scene->addItem(indObjs.at(12));
    for(int i=13;i<16;i++){
        indObjs.push_back(new IndestructibleObject(indObjs.at(i-1)->x()+ indObjs.at(0)->boundingRect().width(),indObjs.at(12)->y()));
        scene->addItem(indObjs.at(i));
    }

    indObjs.push_back(new IndestructibleObject(indObjs.at(0)->x(),indObjs.at(12)->y() + indObjs.at(12)->boundingRect().height()));
    scene->addItem(indObjs.at(16));
    for(int i=17;i<20;i++){
        indObjs.push_back(new IndestructibleObject(indObjs.at(i-1)->x()+ indObjs.at(0)->boundingRect().width(),indObjs.at(16)->y()));
        scene->addItem(indObjs.at(i));
    }
}

void Game::createNormalObject()
{
    NormalObject* nml1=new NormalObject(350,200);
    scene->addItem(nml1);

    NormalObject* nml2=new NormalObject(1000,200);
    scene->addItem(nml2);

    NormalObject* nml3=new NormalObject(350,450);
    scene->addItem(nml3);

    NormalObject* nml4=new NormalObject(1000,450);
    scene->addItem(nml4);

    NormalObject* nml5=new NormalObject(400,200);
    scene->addItem(nml5);

    NormalObject* nml6=new NormalObject(950,200);
    scene->addItem(nml6);

    NormalObject* nml7=new NormalObject(400,450);
    scene->addItem(nml7);

    NormalObject* nml8=new NormalObject(950,450);
    scene->addItem(nml8);

    NormalObject* normal=new NormalObject(base->x()-nml1->boundingRect().width(), height-nml1->boundingRect().height());
    scene->addItem(normal);

    NormalObject* normal1=new NormalObject(normal->x(), normal->y()-normal->boundingRect().height());
    scene->addItem(normal1);

    NormalObject* normal2=new NormalObject(normal1->x() + normal1->boundingRect().width(), normal1->y());
    scene->addItem(normal2);

    NormalObject* normal3=new NormalObject(normal2->x() + normal2->boundingRect().width(), normal1->y());
    scene->addItem(normal3);;

    NormalObject* normal4=new NormalObject(normal3->x() + normal3->boundingRect().width(), normal1->y());
    scene->addItem(normal4);

    NormalObject* normal5=new NormalObject(normal4->x() , normal4->y()+normal4->boundingRect().height());
    scene->addItem(normal5);

    std::vector<NormalObject*> nmlObjs;
    nmlObjs.push_back(new NormalObject(550,350));
    scene->addItem(nmlObjs.at(0));
    for(int i=1;i<6;i++){
        nmlObjs.push_back(new NormalObject(nmlObjs.at(i-1)->x() - nmlObjs.at(0)->boundingRect().width() , nmlObjs.at(0)->y()));
        scene->addItem(nmlObjs.at(i));
    }

    nmlObjs.push_back(new NormalObject(800,350));
    scene->addItem(nmlObjs.at(6));
    for(int i=7;i<12;i++){
        nmlObjs.push_back(new NormalObject(nmlObjs.at(i-1)->x() + nmlObjs.at(0)->boundingRect().width() , nmlObjs.at(0)->y()));
        scene->addItem(nmlObjs.at(i));
    }

}

void Game::checkPlayerBullets()
{
    std::vector<iBullet*>::iterator itr;
    for(itr=playerTank->bullets.begin();itr!=playerTank->bullets.end();itr++){
        if((*itr)==nullptr){
            playerTank->bullets.erase(itr);
        }
    }
}

void Game::checkBotBullets()
{
    std::vector<iBullet*>::iterator itr;
    for(auto a:botTanks){
        for(itr=a->bullets.begin();itr!=a->bullets.end();itr++){
            if((*itr)==nullptr){
                a->bullets.erase(itr);
            }
        }
    }
}



void Game::createBotTanks()
{
    for(int i=0;i<5;i++){
        botTanks.push_back(new BotTank(width,height));
        conditionToCreateBots(botTanks.at(i));
    }
}
