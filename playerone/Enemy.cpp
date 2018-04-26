#include "Enemy.h"
#include <QTimer>

#include <QList>
#include <stdlib.h> // rand() -> really large int
#include <QDebug>
#include "Game.h"

extern Game * game;

Enemy::Enemy(): QObject(), QGraphicsPixmapItem(){
    //set random position
    int random_number = rand() % 700;
    setPos(random_number,0);
    setPixmap(QPixmap(":/images/goomba.png"));

    //setRect(0,0,100,100);
    this->sent = false;
    //connect
    QTimer * timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);

}

void Enemy::move()
{
    setPos(x(), y()+5);
    if (pos().y()> scene()->height()-145){
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
        qDebug() <<"Enemy deleted";
    }
}


