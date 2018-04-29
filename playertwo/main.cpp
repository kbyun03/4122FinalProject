#include <QApplication>
#include <QSplashScreen>
#include "Game.h"
#include <QTimer>
#include "server.h"

Game * game;

int main(int argc, char *argv[])
{
    // show ip address
    foreach (const QHostAddress &address, QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost))
             qDebug() << address.toString();
    }

    QApplication a(argc, argv);
    // we could set window icon

    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/images/Title.png"));
    splash->show();
    QTimer::singleShot(800, splash, SLOT(close()));
    game = new Game();
    game->show();
    Server server(10000);
    server.game = game;




    return a.exec();
}
