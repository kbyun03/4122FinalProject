#include <QApplication>
#include <QSplashScreen>
#include "Game.h"
#include <QTimer>
#include "server.h"

Game * game;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    // we could set window icon

    // show ip address
    QGraphicsScene * addrScene = new QGraphicsScene();
    addrScene->setSceneRect(0,0,480,140);
    QGraphicsTextItem * addrText = new QGraphicsTextItem;
    addrText->setPos(280,30);
    foreach (const QHostAddress &address, QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost))
            addrText->setPlainText("Your IP address:\n\n\t" + address.toString());
    }
    addrScene->addItem(addrText);
    QGraphicsView * view = new QGraphicsView(addrScene);
    view->show();

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
