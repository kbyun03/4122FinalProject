#include "Bullet.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <typeinfo>
#include "Enemy.h"
#include <QList>
#include "Game.h"

extern Game *game; //there is an external global object called game of type Game

Bullet::Bullet()
{
    //draw rect
    setRect(0,0,10,50);

    //connect
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    //if bullet colldes iwth enemy, destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if(typeid (*(colliding_items[i])) == typeid(Enemy)){
            //increase the score
            game->score->increase();

            //remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    //move bullet up
    setPos(x(),y()-10);
    if (pos().y() + rect().height()< 0){
        scene()->removeItem(this);
        delete this;

    }
}
