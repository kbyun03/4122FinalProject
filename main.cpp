#include <QApplication>
#include <QSplashScreen>
#include "Game.h"
#include <QTimer>


Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // we could set window icon

    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/images/Title.png"));
    splash->show();
    QTimer::singleShot(800, splash, SLOT(close()));
    game = new Game();
    game->show();




    return a.exec();
}
