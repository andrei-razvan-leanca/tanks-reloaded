#include <QApplication>
#include"Game.h"

Game* game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    int mode=2, level=3;
    game=Game::getInstance(mode,level);
    game->show();

    return a.exec();
}
