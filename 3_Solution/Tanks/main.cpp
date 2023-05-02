#include <QApplication>
#include"Game.h"

Game* game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //srand(time(NULL));

    game=Game::getInstance();
    game->show();

    return a.exec();
}
