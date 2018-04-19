#include "Enemy.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <stdlib.h>
#include "Game.h"

extern Game *game;
Enemy::Enemy()
{   //set random position
    int random_number = rand()%700;
    setPos(random_number,0);
    //draw rect
    setRect(0,0,50,50);

    //connect
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
    //move enemy down
    setPos(x(),y()+5);
    if (pos().y()> 600){
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}

